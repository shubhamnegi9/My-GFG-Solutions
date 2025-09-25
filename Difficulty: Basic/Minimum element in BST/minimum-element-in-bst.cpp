// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    void inorder(Node* root, vector<int> &sortedInorder) {
        if(root == NULL)
            return;
        
        inorder(root->left, sortedInorder);
        
        sortedInorder.push_back(root->data);
        
        inorder(root->right, sortedInorder);
    }
    
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(n)
    int minValue1(Node* root) {
        if(root == NULL)
            return -1;
        
        vector<int> sortedInorder;
        inorder(root, sortedInorder);
        
        // Inorder traversal of BST gives sorted order
        return sortedInorder[0];
    }
    
    // Optimal Approach
    // T.C. = O(h) 
    // S.C. = O(1)
    int minValue2(Node* root) {
        if(root == NULL)
            return -1;
        
        // Keep going to leftmost node of BST
        while(root->left != NULL)
            root = root->left;
        
        return root->data;
    }
  
    int minValue(Node* root) {
        // Brute Force Approach
        // return minValue1(root);
        
        // Optimal Approach
        return minValue2(root);
    }
};