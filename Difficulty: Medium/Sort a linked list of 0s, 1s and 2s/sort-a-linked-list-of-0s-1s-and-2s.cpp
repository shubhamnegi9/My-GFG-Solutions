/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(2n)
    // S.C. = O(1)
    Node* segregate1(Node* head) {
        Node* temp = head;
        int count0 = 0, count1 = 0, count2 = 0;
        
        // Step 1: finding count of 0s, 1s and 2s
        while(temp) {
            if(temp->data == 0)
                count0++;
            else if(temp->data == 1)
                count1++;
            else
                count2++;
            temp = temp->next;
        }
        
        // Step 2: Data replacement 
        temp = head;
        while(temp) {
            if(count0) {
                temp->data = 0;
                count0--;
            }
            else if(count1) {
                temp->data = 1;
                count1--;
            } 
            else {
                temp->data = 2;
                count2--;
            }
            temp = temp->next;
        }
        
        return head;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    Node* segregate2(Node* head) {
        
        // Edge case
        if(!head || !(head->next))
            return head;
            
        Node* temp = head;
        // Creating 3 dummy nodes 
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        
        // Step 1: Linking all 0s together, all 1s together, all 2s together
        while(temp) {
            if(temp->data == 0) {
                zero->next = temp;
                zero = temp;    // OR  zero = zero->next;
            }
            else if(temp->data == 1) {
                one->next = temp;
                one = temp;     // OR  one = one->next;
            }
            else {
                two->next = temp;
                two = temp;     // OR  two = two->next;
            }
            temp = temp->next;      // Move temp for all if-else cases outside
        }
        
        // Step 2: Linking list of 0s, 1s, and 2s to each other
        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next = NULL;
        
        Node* newHead = zeroHead->next;
        
        // Remove dummy nodes from memory before returning newHead
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
    
    Node* segregate(Node* head) {
        // Brute Force Approach
        // return segregate1(head);
        
        // Optimal Approach
        return segregate2(head);
    }
};