/*
Problem Link : https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1/

Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= N <= 103
*/


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
   // Your code here
   if(node->next == NULL)
    return;
    
   // Find next node using next pointer
    Node *temp  = node->next;

    // Copy data of next node to this node
    node->data  = temp->data;

    // Unlink next node
    node->next  = temp->next;

    // Delete next node
    delete(temp);

    /*** or we can also do it this way ***/
    // Node *temp  = node->next;

    // Copies whole block
    // *node  = *(node->next);

    // Delete next node
    // delete(temp);
}