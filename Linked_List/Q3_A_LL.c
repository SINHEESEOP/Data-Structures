//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section A - Linked List Questions
Purpose: Implementing the required functions for Question 3 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


//////////////////////// function prototypes /////////////////////////////////////

// You should not change the prototype of this function
void moveOddItemsToBack(LinkedList *ll);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;
	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;


	printf("1: Insert an integer to the linked list:\n");
	printf("2: Move all odd integers to the back of the linked list:\n");
	printf("0: Quit:\n");

	while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			moveOddItemsToBack(&ll); // You need to code this function
			printf("The resulting linked list after moving odd integers to the back of the linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

// void moveOddItemsToBack(LinkedList *ll) {
// 	/* add your code here */
//
// 	ListNode *cur, *next, *last;
// 	LinkedList *ll2 = (LinkedList *)malloc(sizeof(LinkedList));
//
// 	cur = ll->head->next;
//
// 	int index = 0;
// 	int index2 = 0;
//
// 	if (cur != NULL && cur->item % 2 == 0) {
// 		insertNode(&ll, index, cur->item);
// 		index++;
// 	}
//
// 	while (cur != NULL) {
//
// 		next = cur->next;
//
// 		if (next->item % 2 == 0) {
// 			insertNode(&ll, index, next->item);
// 			index++;
// 		} else {
// 			insertNode(&ll2, index2, next->item);
// 			index2++;
// 		}
// 	}
//
// 	last = findNode(ll, index);
// 	findNode(ll2, index2)->next = last;
//
// }

// 개선 ver
void moveOddItemsToBack(LinkedList *ll) {
	if (ll == NULL || ll->head == NULL) return;

	ListNode *cur, *next, *last;
	LinkedList *ll2 = (LinkedList *)malloc(sizeof(LinkedList));
	ll2->head = NULL;
	ll2->size = 0;

	cur = ll->head;
	int index = 0;
	int index2 = 0;

	while (cur != NULL) {
		next = cur->next;

		if (cur->item % 2 == 0) {
			insertNode(ll, index, cur->item);
			index++;
		} else {
			insertNode(ll2, index2, cur->item);
			index2++;
		}
		cur = next;
	}

	if (ll->head == NULL) {
		ll->head = ll2->head;
	} else {
		last = findNode(ll, index - 1);
		last->next = ll2->head;
	}

	ll->size = index + index2;
	free(ll2);
}

// void moveOddItemsToBack(LinkedList *ll) {
// 	if (ll == NULL || ll->head == NULL) return;
//
// 	ListNode *cur = ll->head;
// 	int index = 0;
// 	int originalSize = ll->size;
//
// 	// 리스트를 순회하며 홀수 항목을 뒤로 이동시킵니다.
// 	for (int i = 0; i < originalSize; i++) {
// 		if (cur->item % 2 != 0) { // 현재 항목이 홀수인 경우
// 			int oddValue = cur->item;
// 			cur = cur->next;
// 			removeNode(ll, index); // 기존의 removeNode 함수를 활용하여 노드를 제거합니다.
// 			insertNode(ll, ll->size, oddValue); // 기존의 insertNode 함수를 활용하여 홀수를 리스트의 끝에 삽입합니다.
// 		} else {
// 			cur = cur->next;
// 			index++;
// 		}
// 	}
// }


///////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
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

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
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

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
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
