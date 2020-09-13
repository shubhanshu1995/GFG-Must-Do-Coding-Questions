/*
Problem Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45

Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: | represents the bottom pointer.

Note: Try to solve the problem without using any extra space.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

*/


/* Node structure  used in the program */

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};

/***************** This Code uses Merge procedure of Merge Sort of Linked List *************************************/

Node* merge(Node* l1,Node* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    if(l1->data<l2->data)
    {
        l1->bottom=merge(l1->bottom,l2);
        return l1;
    }
    else
    {
        l2->bottom=merge(l1,l2->bottom);
        return l2;
    }
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   // Base cases 
    if (root == NULL || root->next == NULL) 
        return root; 
  
    // Merge this list with the list on right side 
    return merge( root, flatten(root->next) ); 
}