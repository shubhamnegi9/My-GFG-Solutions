// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        int floor = -1;
        
        while(root) {
            if(x == root->data) {
                floor = root->data;
                return floor;
            }
            else if(root->data > x) {
                // Move to left subtree to find smaller value
                root = root->left;
            }
            else {
                // Possible floor value, so update floor
                floor = root->data;
                // Move to right subtree to find greater value
                root = root->right;
            }
        }
        
        return floor;
    }
};