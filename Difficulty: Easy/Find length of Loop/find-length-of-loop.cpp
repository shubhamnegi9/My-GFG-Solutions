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
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n) * O(2*logn) for ordered map for fetching and inserting
    //      = O(n) * O(2) for unordered map for fetching and inserting
    // S.C. = O(n) for map
    int countNodesinLoop1(Node *head) {
        Node* temp = head;
        unordered_map<Node*, int> mpp;
        
        int pos = 1;
        while(temp) {
            if(mpp.find(temp) != mpp.end()) {
                return pos - mpp[temp];
            }    
            
            mpp[temp] = pos;
            pos++;
            temp = temp->next;
        }
        
        return 0;
    }
    
    int findLengthOfLoop(Node* slow, Node* fast) {
        // slow and fast pointers are already pointing to same node (fast == slow) 
        // when this method is called. 
        // So the below while loop will never execute as fast == slow. 
        // Therefore we are making count = 1 and moving fast to next node so that while loop executes. 
        int count = 1;
        fast = fast->next;
        
        while(fast != slow) {
            count++;
            fast = fast->next;
        }
        
        return count;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int countNodesinLoop2(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return findLengthOfLoop(slow, fast);
            }
        }
        
        return 0;
        
    }
    
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Brute Force Approach
        // return countNodesinLoop1(head);
        
        // Optimal Approach
        return countNodesinLoop2(head);
    }
};