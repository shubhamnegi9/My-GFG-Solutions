/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    
    Node* reverseList(Node* head) {
        // Edge case
        if(head == NULL || head->next == NULL)
            return head;
        
        Node* temp = head;
        Node* prev = NULL;
        
        while(temp) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        
        return prev;
    }
  
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        
        Node* t1 = num1;
        Node* t2 = num2;
        int carry = 0;
        Node* dNode = new Node(-1);
        Node* curr = dNode;
        
        while(t1!=NULL || t2!= NULL) {
            int sum = carry;
            
            if(t1!=NULL)
                sum += t1->data;
            if(t2!=NULL)
                sum += t2->data;
            
            Node* newNode = new Node(sum%10);
            carry = sum/10;
            
            curr->next = newNode;
            curr = curr->next;
            
            if(t1!=NULL)
                t1 = t1->next;
            if(t2!=NULL)
                t2 = t2->next;
        }
        
        if(carry == 1) {
            Node* newNode = new Node(1);
            curr->next = newNode;
        }
        
        Node* sumList = reverseList(dNode->next);
        
        Node* temp = sumList;
        
        while(temp) {
            if(temp->data == 0)
                temp = temp->next;
            else
                break;
        }
        
        return temp;
    }
};