/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        Node* temp = head;
        int count = 0;
        
        while(temp) {
            if(count == pos) 
                break;
            count++;
            temp = temp->next;
        }
        
        Node* front = temp->next;
        
        if(front == NULL) {     // temp is last node of DLL, and newNode is inserted after temp
            Node* newNode = new Node(data);
            newNode->next = NULL;
            newNode->prev = temp;
            temp->next = newNode;
            return head;
        }
        
        // temp is any node in middle of DLL, and newNode is inserted after temp
        Node* newNode = new Node(data);
        newNode->next = front;
        newNode->prev = temp;
        temp->next = newNode;
        front->prev = newNode;
        return head;
        
    }
};