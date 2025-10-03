/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void inorder(Node* root, int k, int& count, int& kthLargest) {
        if(root == NULL)
            return;
        
        inorder(root->left, k, count, kthLargest);
        
        count++;
        if(count == k) {
            kthLargest = root->data;
            return;
        }
        
        inorder(root->right, k, count, kthLargest);
    }
  
    void countNodes(Node* root, int k, int& count) {
        if(root == NULL)
            return;
        
        count++;
        countNodes(root->left, k, count);
        countNodes(root->right, k, count);
    }
    
    int kthLargest1(Node *root, int k) {
        int n = 0;
        countNodes(root, k, n);
        int count = 0, kthLargest = 0;
        inorder(root, n-k+1, count, kthLargest);
        
        return kthLargest;
    }
    
    void reverseInorder(Node* root, int k, int& count, int& kthLargest) {
        if(root == NULL)
            return;
        
        reverseInorder(root->right, k, count, kthLargest);
        
        count++;
        if(count == k) {
            kthLargest = root->data;
            return;
        }
        
        reverseInorder(root->left, k, count, kthLargest);
    }
    
    int kthLargest2(Node *root, int k) {
        int count = 0, kthLargest = 0;
        reverseInorder(root, k, count, kthLargest);
        return kthLargest;
    }
    
    int kthLargest(Node *root, int k) {
        // First Approach
        // return kthLargest1(root, k);
        
        // Second Approach
        return kthLargest2(root, k);
    }
};