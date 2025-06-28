/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(2n)
    // S.C. = O(n) for stack
    DLLNode* reverseDLL1(DLLNode* head) {
        
        // Corner case
        if(head == NULL || head->next == NULL)
            return head;
            
        DLLNode* temp = head;
        stack<int> st;
        
        while(temp) {
            st.push(temp->data);
            temp = temp->next;
        }
        
        temp = head;    // Resetting temp back to head
        while(temp) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        
        return head;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    DLLNode* reverseDLL2(DLLNode* head) {
        
        // Corner case
        if(head == NULL || head->next == NULL)
            return head;
        
        DLLNode* curr = head;
        DLLNode* last = NULL;
        
        while(curr) {
            // Swap the next and prev pointers
            last = curr->prev;
            curr->prev = curr->next;
            curr->next = last;
            
            // Move to next node in reversed list
            curr = curr->prev;
        }
        
        return last->prev;      // last->prev will point to head of reversed DLL
    }
    
  
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Brute Force Approach
        // return reverseDLL1(head);
        
        // Optimal Approach
        return reverseDLL2(head);
        
    }
};