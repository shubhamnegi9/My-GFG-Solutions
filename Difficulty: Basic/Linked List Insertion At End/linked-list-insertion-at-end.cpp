/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if(head == NULL) {
            Node* newNode = new Node(x);
            return newNode;
        }
            
        
        Node* temp = head;
        Node* newNode = new Node(x);
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
};