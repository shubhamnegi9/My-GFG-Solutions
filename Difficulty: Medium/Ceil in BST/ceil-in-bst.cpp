class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil = -1;
        
        while(root) {
            if(x == root->data) {
                ceil = root->data;
                return ceil;
            }
            else if(root->data < x) {
                // Look for greater value in right subtree
                root = root->right;
            }
            else {
                ceil = root->data;
                // Look for smaller value in left subtree
                root = root->left;
            }
        }
        
        return ceil;
    }
};
