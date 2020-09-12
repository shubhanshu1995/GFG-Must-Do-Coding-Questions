/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Recursive Approach
*/


/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    
    if(head->next == NULL)
        return head;
        
    Node *newHead = reverseList(head->next);
    Node *q = head->next;
    q->next = head;
    head->next = NULL;
    
    return newHead;
}
