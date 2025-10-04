/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* successor = NULL;
        Node* predecessor = NULL;
        
        Node* temp = root;
        
        // Finding inorder successor
        while(temp != NULL) {
            if(temp->data <= key) {
                temp = temp->right;     // Moving right to find greater value
            }
            else {
                successor = temp;
                temp = temp->left;      // Moving left to find smaller value
            }
        }
        
        temp = root;
        
        // Finding inorder predecessor
        while(temp != NULL) {
            if(temp->data >= key) {
                temp = temp->left;      // Moving left to find smaller value
            }
            else {
                predecessor = temp;
                temp = temp->right;     // Moving right to find greater value
            }
        }
        
        return {predecessor, successor};
    }
};