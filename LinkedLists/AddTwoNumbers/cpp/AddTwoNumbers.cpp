/*
Problem Link : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  

Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= N, M <= 5000


Approach:

1) Reverse First List.
2) Reverse Second List.
3) Perform addition on both Lists & store result in new List.
4) Reverse Final answer List.
*/


/* node for linked list: */

struct Node {
    int data;
    struct Node* next;
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

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    first = reverseList(first); // Reversing first List
    second = reverseList(second); // Reversing second List
    
    Node *dummyNode = new Node(0);
    Node *third = dummyNode;
    
    int carry = 0;
    while(first != NULL || second != NULL)
    {
        int first_val = (first != NULL) ? first->data:0;
        int second_val = (second != NULL) ? second->data:0;
        
        int current_sum = first_val + second_val + carry;
        carry = current_sum / 10;
        int last_digit = current_sum % 10;
        
        Node *newNode = new Node(last_digit);
        third->next = newNode;
        
        if(first != NULL)
            first = first->next;
            
        if(second != NULL)
            second = second->next;
            
        third = third->next;
    }
    
    if(carry > 0)
    {
        Node *newCarryNode = new Node(carry);
        third->next = newCarryNode;
        third = third->next;
    }
    
    // Reversing final list
    Node *finalDummyHead = reverseList(dummyNode->next);
    
    return finalDummyHead;
}
