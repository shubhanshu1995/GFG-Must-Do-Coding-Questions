/*
Problem Link : https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/

Input:
LinkList1 = {10,20,5,10}
LinkList2 = {30,40,50,5,10}
Output: 5

Explanation:The point of intersection of
two linked list is 5, means both of them
get linked (intersects) with each other
at node whose value is 5.

Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

*/

/********************* This Method is tricky one, doesn't work when data is zero or negative*********************/ 

/* Linked List Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   
int intersectPoint(Node* head1, Node* head2)
{
    Node *temp = head1;
    while(temp)
    {
        temp->data = -1 * temp->data;
        temp = temp->next;
    }
    temp = head2;
    int ans = -1;
    
    while(temp)
    {
        if(temp->data < 0)
        {
            ans = -1*temp->data;
            break;
        }
        temp = temp->next;
    }
    return ans;
}