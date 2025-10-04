/*The structure of Node

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

class Solution {
  public:
    
    void inorder(Node* root, vector<int>& ans) {
        if(root == NULL)
            return;
        
        inorder(root->left, ans);
        
        ans.push_back(root->data);
        
        inorder(root->right, ans);
    }
    
    int findUsingBS(vector<int>& ans, int x) {
        int l = 0, r = ans.size()-1;
        
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(ans[mid] == x) {
                if(mid+1 <= ans.size()-1)
                    return ans[mid+1];      // Returning element after ans[mid]
                else
                    return -1;
            }
            else if(ans[mid] < x) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        
        return -1;
    }
  
    // Brute Force Approach
    // T.C. = O(n) + O(logn) using BS
    // S.C. = O(n) for vector
    int inOrderSuccessor1(Node *root, Node *x) {
        vector<int> ans;
        inorder(root, ans);
        
        return findUsingBS(ans, x->data);
    }
    
    void inorder(Node* root, Node *x, int& ans, bool& found) {
        if(found || root == NULL)
            return;
        
        inorder(root->left, x, ans, found);
        
        if(!found && root->data > x->data) {
            ans = root->data;
            found = true;
            return;
        }
        
        inorder(root->right, x, ans, found);
    }
    
    // Better Approach
    // T.C. = O(n)
    // S.C. = O(1) extra space
    int inOrderSuccessor2(Node *root, Node *x) {
        int ans = -1;
        bool found = false;
        inorder(root, x, ans, found);
        return ans;
    }
    
    // Optimal Approach
    // T.C. = O(h)
    // S.C. = O(1) extra space
    int inOrderSuccessor3(Node *root, Node *x) {
        int successor = -1;
        
        while(root != NULL) {
            
            if(root->data <= x->data) {
                root = root->right;
            }
            else {
                successor = root->data;
                root = root->left;
            }
        }
        
        return successor;
    }
    
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Brute Force Approach
        // return inOrderSuccessor1(root, x);
        
        // Better Approach
        return inOrderSuccessor2(root, x);
        
        // Optimal Approach
        // return inOrderSuccessor3(root, x);
    }
};