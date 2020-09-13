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


/* Linked List Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


int getLength(struct Node* head) 
{ 
    struct Node* current = head; 
    int len = 0; 
  
    while (current != NULL) { 
        len++; 
        current = current->next; 
    } 
  
    return len; 
}

int intersectPointUtility(Node* head1, Node* head2,int diff)
{
    Node *current1 = head1;
    Node *current2 = head2;
    
    for(int i = 0;i<diff;++i)
    {
        if(current1 == NULL)
            return -1;
        current1 = current1->next;
    }
    
    while(current1 != NULL && current2 != NULL)
    {
        if(current1 == current2)
            return current1->data;
            
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return -1;
}

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    int m = getLength(head1);
    int n = getLength(head2);
    
    int diff;
    
    if(m > n)
    {
        diff = m - n;
        return intersectPointUtility(head1,head2,diff);
    }
    else
    {
        diff = n - m;
        return intersectPointUtility(head2,head1,diff);
    }
}