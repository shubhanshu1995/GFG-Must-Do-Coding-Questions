/*
Problem Link : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 50

Alter Approach is to use stack, but it consumes O(n) space. Here I'm solving this problem in O(1) space complexity.
*/


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    
    Node *prev,*current,*next;
    prev = NULL;
    current = head;
        
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    
    return head;
}

/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    Node *slowPtr = head;
    Node *fastPtr = head;
    
    while(fastPtr !=NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    
    // slowPtr points to middle element of list
    
    //Now we will reverse second half of the list
    slowPtr = reverseList(slowPtr);
    fastPtr = head;
    
    //Checking for palindrome in two lists
    while(slowPtr != NULL)
    {
        if(slowPtr->data != fastPtr->data)
            return false;
            
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    return true;
}