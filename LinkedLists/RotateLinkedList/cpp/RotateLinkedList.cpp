/*
Problem Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

Input:
N = 8
value[] = {1,2,3,4,5,6,7,8}
k = 4
Output: 5 6 7 8 1 2 3 4
*/


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k)
{
    if (k == 0) 
        return head; 
  
    Node* current = head; 
  
    // current will either point to kth node or NULL after this loop. 
    int count = 1; 
    while (count < k && current != NULL) { 
        current = current->next; 
        count++; 
    } 
  
    // If current is NULL, k is greater than or equal to count 
    // of nodes in linked list. Don't change the list in this case 
    if (current == NULL) 
        return head; 
  
    // current points to kth node. Store it in a variable. 
    Node* kthNode = current; 
  
    // current will point to last node after this loop 
    while (current->next != NULL) 
        current = current->next; 
  
    // Change next of last node to previous head 
    current->next = head; 
  
    // Change head to (k+1)th node 
    head = kthNode->next; 
  
    // change next of kth node to NULL 
    kthNode->next = NULL; 
    
    return head;
}
