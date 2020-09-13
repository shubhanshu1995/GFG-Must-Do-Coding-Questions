/*
Problem Link : https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5

Explanation: After sorting the given
linked list, the resultant Linked List
will be 1->2->3->4->5.

/*

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node* merge(Node* l1,Node* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    if(l1->data<l2->data)
    {
        l1->next=merge(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next=merge(l1,l2->next);
        return l2;
    }
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) 
{
    // your code here
    if(head==NULL || head->next==NULL)
        return head;

    Node* slow=head;
    Node* fast=head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    
    /* 1->3->5->4->2->6 (even number of nodes)
       here slow will be 5, actual mid point is 4
       For further info refer middle element in linked list problem
       
       1->3->5->4->2 (odd number of nodes)
       here slow will be 5
    */
    
    Node* newHead=slow->next;
    slow->next=NULL;
    
    return merge(mergeSort(head),mergeSort(newHead));

}