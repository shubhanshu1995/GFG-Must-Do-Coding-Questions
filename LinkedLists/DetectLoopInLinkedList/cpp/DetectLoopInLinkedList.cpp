/*
Problem Link : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

Using Floyd's Cycle detection algorithm
Slow Pointer & Fast Pointer Concept

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/


bool detectLoop(Node* head)
{
    // your code here
        
    Node *slowPtr = head;
    Node *fastPtr = head;
    
    while(fastPtr !=NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        
        if(slowPtr == fastPtr)
            return true;
    }
    
    return false;
}
