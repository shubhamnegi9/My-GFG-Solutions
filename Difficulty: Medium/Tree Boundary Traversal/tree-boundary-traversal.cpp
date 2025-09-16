/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }
    
    void addLeftBoundaryNodes(Node* node, vector<int>& result) {
        while(node) {
            if(!isLeaf(node)) {
                result.push_back(node->data);
            }   
            if(node->left)
                node = node->left;
            else
                node = node->right;
        }
    }
    
    void addLeafNodes(Node* node, vector<int>& result) {
        // Using Preorder Traversal 
        if(isLeaf(node)) {
            result.push_back(node->data);
            return;
        }
        if(node->left)
            addLeafNodes(node->left, result);
        if(node->right)
            addLeafNodes(node->right, result);
    }
    
    void addRightBoundaryNodes(Node* node, vector<int>& result) {
        vector<int> temp;
        while(node) {
            if(!isLeaf(node)) {
                temp.push_back(node->data);
            }   
            if(node->right)
                node = node->right;
            else
                node = node->left;
        }
        int n = temp.size();
        // Pushing in result from bottom to top
        for(int i = n-1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }
    
    // T.C. = O(h) + O(n) + O(h)
    // S.C. = O(n)
    vector<int> boundaryTraversal(Node *root) {
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        // Initially push root node in result if it is not leaf node
        if(!isLeaf(root))
            result.push_back(root->data);
            
        addLeftBoundaryNodes(root->left, result);
        addLeafNodes(root, result);
        addRightBoundaryNodes(root->right, result);
        
        return result;
    }
};