/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Iterative Approach
*/



/* Linked List Node structure: */

struct Node
{
    int data;
    struct Node *next;
};

// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    
    Node *prev,*current,*next;
    prev = NULL;
    current = head;
    
    // if(head->next == NULL)
    //     return head;
        
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    
    return head;
}