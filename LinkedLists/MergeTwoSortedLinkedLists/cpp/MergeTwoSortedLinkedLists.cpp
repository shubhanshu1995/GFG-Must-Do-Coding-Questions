/*
Problem Link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

Input:
N = 2, M = 2

valueN[] = {1,1}
valueM[] = {2,4}

Output:1 1 2 4

Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)
*/


/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/***************** This Code uses Merge procedure of Merge Sort of Linked List *************************************/

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    // code here
    if(!head_A)
        return head_B;
    if(!head_B)
        return head_A;

    if(head_A->data < head_B->data)
    {
        head_A->next = sortedMerge(head_A->next,head_B);
        return head_A;
    }
    else
    {
        head_B->next = sortedMerge(head_A,head_B->next);
        return head_B;
    }
}