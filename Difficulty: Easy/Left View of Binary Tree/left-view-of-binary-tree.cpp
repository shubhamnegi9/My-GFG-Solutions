/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    
    void getLeftView(Node* root, vector<int>& result, int level) {
        
        if(root == NULL)
            return;
        
        // Preorder Traversal
        
        if(level == result.size()) {
            result.push_back(root->data);
        }
        
        getLeftView(root->left, result, level+1);
        getLeftView(root->right, result, level+1);
        
    }
  
    vector<int> leftView(Node *root) {
        vector<int> result;
        getLeftView(root, result, 0);
        return result;
    }
};