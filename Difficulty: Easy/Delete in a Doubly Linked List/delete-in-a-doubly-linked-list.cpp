/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    
    Node* deleteHead(Node* head) {
        if(head == NULL || head->next == NULL)
            return NULL;
            
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    
    Node* deleteTail(Node* head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        Node* back = temp->prev;
        temp->prev = nullptr;
        back->next = nullptr;
        delete temp;
        return head;
    }
  
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        if(head == NULL) {
            return NULL;
        }
        
        int count = 0;
        Node* temp = head;
        while(temp->next != NULL) {
            count++;
            if(count == x) {
                break;
            }
            
            temp = temp->next;
        } 
        
        Node* back = temp->prev;
        Node* front = temp->next;
        
        if(back == NULL && front == NULL) {
            delete temp;
            return NULL;
        }
        else if(back == NULL) {
            return deleteHead(head);
        }
        else if(front == NULL) {
            return deleteTail(head);
        }
        
        back->next = front;
        front->prev = back;
        temp->next = temp->prev = NULL;
        delete temp;
        return head;
    }
};