/*
Problem Link: https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

This problem is just a variation of Reverse a Linked List in groups of given size

Input:
LinkedList: 1->2->2->4->5->6->7->8
Output: 2 1 4 2 6 5 8 7
Explanation: After swapping each pair
considering (1,2), (2, 4), (5, 6).. so
on as pairs, we get 2, 1, 4, 2, 6, 5,
8, 7 as a new linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
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


Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
    Node *prev,*current,*next;
    
    prev = NULL;
    current = head;
    
    int count = 1;
    int k = 2; // group of 2
    while(count <= k && current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        
        count++;
    }
    
    if (next !=  NULL) 
       head->next = pairWiseSwap(next);  
  
    /* prev is new head of the input list */
    return prev; 
}