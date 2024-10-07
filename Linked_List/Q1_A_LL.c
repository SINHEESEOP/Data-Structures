//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 자료구조
Lab Test: Section A - 연결 리스트 문제
목적: 문제 1을 위한 필수 함수 구현 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;			// ListNode의 정의는 변경하지 마세요.

typedef struct _linkedlist{
	int size;
	ListNode *head;
} LinkedList;		// LinkedList의 정의는 변경하지 마세요.


///////////////////////// 함수 프로토타입 //////////////////////////////////////

// 이 함수의 프로토타입은 변경하지 마세요.
int insertSortedLL(LinkedList *ll, int item);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main()
{

	// 콘솔 출력 및 입력 코드 페이지를 UTF-8로 설정
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	LinkedList ll;
	int c, i, j;
	c = 1;

	// 기존 ll.head 접근 방식은 (*ll).head로 수정 가능
	// printf("ll->head 주소: %p\n", (void*) ll.head);

	// 연결 리스트를 빈 리스트로 초기화합니다.
	ll.head = NULL;
	ll.size = 0;

	printf("1: 정렬된 연결 리스트에 정수를 삽입하기:\n");
	printf("2: 가장 최근에 입력한 값의 인덱스 출력:\n");
	printf("3: 정렬된 연결 리스트 출력:\n");
	printf("0: 종료:");

	while (c != 0)
	{
		printf("\n선택을 입력하세요(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("연결 리스트에 추가할 정수를 입력하세요: ");
			scanf("%d", &i);
			j = insertSortedLL(&ll, i);
			printf("결과 연결 리스트는: ");
			printList(&ll);
			break;
		case 2:
			printf("값 %d는 인덱스 %d에 추가되었습니다\n", i, j);
			break;
		case 3:
			printf("결과 정렬된 연결 리스트는: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("알 수 없는 선택입니다;\n");
			break;
		}


	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

// int insertSortedLL(LinkedList *ll, int item)
// {
// 	/* 여기에 코드를 추가하세요 */
// 	ListNode *newNode, *prev, *cur;
// 	int index = 0;
//
// 	// 새 노드 생성
// 	newNode = (ListNode *)malloc(sizeof(ListNode));
// 	if (newNode == NULL)
// 		return -1;
//
// 	newNode->item = item;
// 	newNode->next = NULL;
//
// 	// 빈 리스트일 경우, 첫 번째 노드로 삽입
// 	if (ll->head == NULL || ll->head->item >= item) {
// 		newNode->next = ll->head;
// 		ll->head = newNode;
// 	} else {
// 		// 노드들이 정렬된 상태에서 삽입 위치 찾기
// 		cur = ll->head;
// 		while (cur != NULL && cur->item < item) {
// 			prev = cur;
// 			cur = cur->next;
// 			index++;
// 		}
// 		prev->next = newNode;
// 		newNode->next = cur;
// 	}
//
// 	ll->size++;
// 	return index;  // 삽입된 위치의 인덱스 반환
// }

int insertSortedLL(LinkedList *ll, int item) {

	ListNode *cur = ll->head;
	int index = 0;

	// 리스트를 순회하면서 삽입할 위치를 찾기 (정렬된 순서 유지)
	while (cur != NULL && cur->item < item) {
		cur = cur->next;
		index++;
	}

	// insertNode 함수를 사용하여 값을 삽입
	if (insertNode(ll, index, item) == 0) {
		return index;  // 삽입된 위치의 인덱스 반환
	} else {
		return -1;  // 삽입 실패 시 -1 반환
	}

}


///////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("빈 리스트");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode *findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// 비어있는 리스트이거나 첫 번째 노드를 삽입하는 경우, 헤드 포인터를 업데이트해야 합니다.
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// 삽입 위치 전후의 노드를 찾고, 새로운 노드를 생성하여 연결을 재구성합니다.
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// 제거할 수 있는 최대 인덱스는 size-1입니다.
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// 첫 번째 노드를 제거하는 경우, 헤드 포인터를 업데이트해야 합니다.
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// 제거할 위치 전후의 노드를 찾고, 대상 노드를 해제한 후 연결을 재구성합니다.
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
