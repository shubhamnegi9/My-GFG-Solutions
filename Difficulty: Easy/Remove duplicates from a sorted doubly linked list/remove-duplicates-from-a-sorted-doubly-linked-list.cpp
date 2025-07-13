/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:
    // T.C. = O(n)
    // S.C. = O(1)
    Node *removeDuplicates(struct Node *head) {
        Node* temp = head;
        
        // If temp is at last node, then there will be no duplicates after it
        // Therefore we put temp->next != NULL condition also
        while(temp != NULL && temp->next != NULL) {
            Node* nextNode = temp->next;
            
            // While moving nextNode, it may become NULL. 
            // Therefore we put nextNode != NULL condition also
            while(nextNode != NULL && nextNode->data == temp->data) {
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;       // Free up the memory for duplicate nodes
            }
            
            temp->next = nextNode;
            // Check for nextNode != NULL before linking its prev pointer to temp
            if(nextNode != NULL)
                nextNode->prev = temp;
            
            temp = temp->next;  // temp will point to next unique node
        }
        
        return head;
    }
};