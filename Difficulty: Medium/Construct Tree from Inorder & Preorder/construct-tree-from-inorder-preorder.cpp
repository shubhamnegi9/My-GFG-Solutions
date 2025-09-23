// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    
    Node* buildSubtree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inorderMap) {
        // Base case
        if((preStart > preEnd) || (inStart > inEnd))
            return NULL;
        
        Node* root = new Node(preorder[preStart]);
        
        int inRootPos = inorderMap[root->data];
        int numsLeft = inRootPos - inStart;
        
        root->left = buildSubtree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRootPos-1, inorderMap);
        root->right = buildSubtree(preorder, preStart+numsLeft+1, preEnd, inorder, inRootPos+1, inEnd, inorderMap);
        
        return root;
    }
    
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> inorderMap;
        
        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildSubtree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorderMap);
    }
};