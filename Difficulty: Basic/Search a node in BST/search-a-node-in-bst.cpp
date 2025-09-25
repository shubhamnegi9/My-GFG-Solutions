/*
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
bool search(Node* root, int x) {
    
    while(root != NULL && root->data != x) {
        root = (x < root->data) ? root->left : root->right;
    }
    
    return (root != NULL) ? true : false;
}