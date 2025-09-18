/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> result;
        
        if(root == NULL)
            return result;
            
        queue<pair<Node*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});  // root node is at line 0
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            Node* node = p.first;
            int line = p.second;
            // Only push in map if there is no value for that key line
            if(mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }
            
            if(node->left) {
                q.push({node->left, line-1});
            }
            if(node->right) {
                q.push({node->right, line+1});
            }
        }
        
        for(auto it: mpp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};