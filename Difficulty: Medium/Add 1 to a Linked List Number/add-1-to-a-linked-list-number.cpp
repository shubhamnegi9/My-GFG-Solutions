/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverseList(Node* head) {     // O(n)
        // Edge Case
        if(head == NULL || head->next == NULL)
            return head;
        
        Node* temp = head;
        Node* prev = NULL;
        
        while(temp != NULL) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;   // OR temp = temp->next;
        }
        
        return prev;
    }
    
    // Brute Force Approach
    // T.C. = O(n) for reversing LL + O(n) for adding 1 to LL + O(n) for reversing LL
    //      = O(3n)
    // S.C. = O(1)
    Node* addOne1(Node* head) {
        head = reverseList(head);
        Node* temp = head;
        int carry = 1;
        
        while(temp) {
            temp->data = temp->data + carry;
            
            if(temp->data < 10) {
                carry = 0;
                break;
            } else {
                // If temp->data == 10
                temp->data = 0;
                carry = 1;
            }
            
            temp = temp->next;
        }
        
        head = reverseList(head);
        
        if(carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        
        return head;        // If carry is 0
    }
    
    int addOneRecursive(Node* temp) {
        // Base case
        if(temp == NULL) {
            return 1;       // Return 1 as carry from base case
        }
        
        int carry = addOneRecursive(temp->next);
        
        // Backtracking from here
        
        // Carry from next node is added to current node's value
        temp->data = temp->data + carry;    
        
        if(temp->data < 10) {
            return 0;       // Return 0 as carry 
        }
        
        // If temp->data == 10
        temp->data = 0;
        return 1;          // Return 1 as carry 
    }
    
    // Optimal Approach 
    // T.C. = O(n)
    // S.C. = O(n) for recursive stack space
    Node* addOne2(Node* head) {
        Node* temp = head;
        int carry = addOneRecursive(head);
        
        if(carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        
        return head;    // If carry is 0
    }
    
    Node* addOne(Node* head) {
        // Brute Force Approach
        // return addOne1(head);
        
        // Optimal Approach
        return addOne2(head);
    }
};