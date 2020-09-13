/*
Problem Link : https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
*/

struct Node 
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// This function is to segregate the elememtns in the linked list
Node* segregate(Node *head) {
    
    // Add code here
    int count0 = 0, count1 = 0, count2 = 0;
    
    Node *curr = head;
    while(curr != NULL)
    {
        if(curr->data == 0)
        {
            count0++;
        }
        else if(curr->data == 1)
        {
            count1++;
        }
        else if(curr->data == 2)
        {
            count2++;
        }
        
        curr = curr->next;
    }
    
    curr = head;
    while(curr != NULL)
    {
        if(count0 != 0)
        {
            curr->data = 0;
            count0--;
        }
        else if(count1 != 0)
        {
            curr->data = 1;
            count1--;
        }
        else if(count2 != 0)
        {
            curr->data = 2;
            count2--;
        }
        
        curr = curr->next;
    }
    
    return head;
    
}