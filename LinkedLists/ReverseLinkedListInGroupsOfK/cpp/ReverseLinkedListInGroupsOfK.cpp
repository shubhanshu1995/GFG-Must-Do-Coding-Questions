/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

Reverse a Linked List in groups of given size.

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4->2->2->1->8->7->6->5
*/

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;

struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    node *prev,*current,*next;
    
    prev = NULL;
    current = head;
    
    int count = 1;
    
    while(count <= k && current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        
        count++;
    }
    
    if (next !=  NULL) 
       head->next = reverse(next, k);  
  
    /* prev is new head of the input list */
    return prev; 
    
}