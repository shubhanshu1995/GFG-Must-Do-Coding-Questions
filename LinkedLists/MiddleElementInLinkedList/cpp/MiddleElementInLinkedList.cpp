/*
Problem Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

Using fast & slow pointer strategy
*/



/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   Node *slowPtr = head;
   Node *fastPtr = head;
   
   while(fastPtr != NULL && fastPtr->next != NULL)
   {
       slowPtr = slowPtr->next;
       fastPtr = fastPtr->next->next;
   }
   
   return slowPtr->data;
}
