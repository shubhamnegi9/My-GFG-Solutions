/* Print he nth node in the linked list Node is defined as
/* Link list node
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Should return data of node at given index. The function may
//  assume that there are at least index+1 nodes in linked list

class Solution {
  public:
    int GetNth(Node *head, int index) {
        Node* temp = head;
        int count = 0;
        
        while(temp != NULL) {
            count++;
            if(count == index) {
                return temp->data;
            }
            temp = temp->next;
        }
        
        return -1;
    }
};