#cmake_minimum_required(VERSION 3.29)
#project(Data_Structures C)
#
#set(CMAKE_C_STANDARD 11)
#
#add_executable(Data_Structures
#    Binary_Search_Tree/Q1_F_BST.c
#    Binary_Search_Tree/Q2_F_BST.c
#    Binary_Search_Tree/Q3_F_BST.c
#    Binary_Search_Tree/Q4_F_BST.c
#    Binary_Search_Tree/Q5_F_BST.c
#    Binary_Tree/Q1_E_BT.c
#    Binary_Tree/Q2_E_BT.c
#    Binary_Tree/Q3_E_BT.c
#    Binary_Tree/Q4_E_BT.c
#    Binary_Tree/Q5_E_BT.c
#    Binary_Tree/Q6_E_BT.c
#    Binary_Tree/Q7_E_BT.c
#    Binary_Tree/Q8_E_BT.c
#    Linked_List/Q1_A_LL.c
#    Linked_List/Q2_A_LL.c
#    Linked_List/Q3_A_LL.c
#    Linked_List/Q4_A_LL.c
#    Linked_List/Q5_A_LL.c
#    Linked_List/Q6_A_LL.c
#    Linked_List/Q7_A_LL.c
#    Stack_and_Queue/Q1_C_SQ.c
#    Stack_and_Queue/Q2_C_SQ.c
#    Stack_and_Queue/Q3_C_SQ.c
#    Stack_and_Queue/Q4_C_SQ.c
#    Stack_and_Queue/Q5_C_SQ.c
#    Stack_and_Queue/Q6_C_SQ.c
#    Stack_and_Queue/Q7_C_SQ.c)

cmake_minimum_required(VERSION 3.29)
project(Data_Structures C)

set(CMAKE_C_STANDARD 11)

# Binary Search Tree
add_executable(Q1_F_BST Binary_Search_Tree/Q1_F_BST.c)
add_executable(Q2_F_BST Binary_Search_Tree/Q2_F_BST.c)
add_executable(Q3_F_BST Binary_Search_Tree/Q3_F_BST.c)
add_executable(Q4_F_BST Binary_Search_Tree/Q4_F_BST.c)
add_executable(Q5_F_BST Binary_Search_Tree/Q5_F_BST.c)

# Binary Tree
add_executable(Q1_E_BT Binary_Tree/Q1_E_BT.c)
add_executable(Q2_E_BT Binary_Tree/Q2_E_BT.c)
add_executable(Q3_E_BT Binary_Tree/Q3_E_BT.c)
add_executable(Q4_E_BT Binary_Tree/Q4_E_BT.c)
add_executable(Q5_E_BT Binary_Tree/Q5_E_BT.c)
add_executable(Q6_E_BT Binary_Tree/Q6_E_BT.c)
add_executable(Q7_E_BT Binary_Tree/Q7_E_BT.c)
add_executable(Q8_E_BT Binary_Tree/Q8_E_BT.c)

# Linked List
add_executable(Q1_A_LL Linked_List/Q1_A_LL.c)
add_executable(Q2_A_LL Linked_List/Q2_A_LL.c)
add_executable(Q3_A_LL Linked_List/Q3_A_LL.c)
add_executable(Q4_A_LL Linked_List/Q4_A_LL.c)
add_executable(Q5_A_LL Linked_List/Q5_A_LL.c)
add_executable(Q6_A_LL Linked_List/Q6_A_LL.c)
add_executable(Q7_A_LL Linked_List/Q7_A_LL.c)

# Stack and Queue
add_executable(Q1_C_SQ Stack_and_Queue/Q1_C_SQ.c)
add_executable(Q2_C_SQ Stack_and_Queue/Q2_C_SQ.c)
add_executable(Q3_C_SQ Stack_and_Queue/Q3_C_SQ.c)
add_executable(Q4_C_SQ Stack_and_Queue/Q4_C_SQ.c)
add_executable(Q5_C_SQ Stack_and_Queue/Q5_C_SQ.c)
add_executable(Q6_C_SQ Stack_and_Queue/Q6_C_SQ.c)
add_executable(Q7_C_SQ Stack_and_Queue/Q7_C_SQ.c)
