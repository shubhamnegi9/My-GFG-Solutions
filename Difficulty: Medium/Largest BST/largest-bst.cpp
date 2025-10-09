/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue {
    public:
    int smallest, largest, size;
    
    NodeValue(int smallest, int largest, int size) {
        this->smallest = smallest;
        this->largest = largest;
        this->size = size;
    }
};


class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue largestBstUtil(Node* root) {
        if(root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);
        
        NodeValue left = largestBstUtil(root->left);
        NodeValue right = largestBstUtil(root->right);
        
        // Cuurent root forms BST
        if(left.largest < root->data && root->data < right.smallest) {
            return NodeValue(min(left.smallest, root->data), max(right.largest, root->data), left.size + right.size + 1);
        }
        
        // Cuurent root does not forms BST
        return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
    }
    
    int largestBst(Node *root) {
        
        // Optimal Approach
        return largestBstUtil(root).size;
    }
};