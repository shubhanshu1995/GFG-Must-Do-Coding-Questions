/*
Problem Link : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8


Example 2:

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1

Note:
Try to solve in single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

/*


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
  // Your code here
  Node *main_ptr = head; 
  Node *ref_ptr = head; 
  
  int count = 0; 
  
  if(head == NULL || head->next == NULL)
    return -1;

  while( count < n ) 
  { 
    if(ref_ptr == NULL) 
        return -1; // n is greater than number of nodes
    ref_ptr = ref_ptr->next; 
    count++; 
  }

  while(ref_ptr != NULL) 
  { 
    main_ptr = main_ptr->next; 
    ref_ptr  = ref_ptr->next; 
  } 
  
  return main_ptr->data; 
}