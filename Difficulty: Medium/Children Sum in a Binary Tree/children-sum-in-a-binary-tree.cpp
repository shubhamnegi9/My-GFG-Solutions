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
    // Using recursive DFS traversal
    int isSumProperty1(Node *root) {
        // If node is empty or leaf node, return 1
        if(root == NULL || (root->left == NULL && root->right == NULL)) {
            return 1;
        }
        
        int sum = 0;
        
        if(root->left)
            sum += root->left->data;
        
        if(root->right)
            sum += root->right->data;
        
        return (sum == root->data && isSumProperty1(root->left) && isSumProperty1(root->right));
    }
    
    int isSumProperty(Node *root) {
        // Using recursive DFS traversal
        return isSumProperty1(root);
    }
};