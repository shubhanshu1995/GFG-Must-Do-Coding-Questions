/*
Problem Link : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

Using Floyd's Cycle detection algorithm
Slow Pointer & Fast Pointer Concept

/*


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
 
    Node *slowPtr = head;
    Node *fastPtr = head;
    Node *prevSlowPtr = NULL;
    while(fastPtr !=NULL && slowPtr !=NULL && fastPtr->next != NULL)
    {
        prevSlowPtr = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        
        if(slowPtr == fastPtr)
            break;
    }
 
    // If loop does not exist
    if (slowPtr != fastPtr)
        return;
 
    // If loop exists. Start slowPtr from
    // head and fastPtr from meeting point.

    slowPtr = head;
    Node *prevFastPtr = NULL;
    bool flag = false;
    while (slowPtr != fastPtr) {
        slowPtr = slowPtr->next;
        prevFastPtr = fastPtr;
        fastPtr = fastPtr->next;
        flag = true;
    }
    
    if(!flag) // When loop ends at head node i.e. last node points to first node 
        prevSlowPtr->next = NULL;
    else
        prevFastPtr->next = NULL;
}