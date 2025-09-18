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
    vector<int> bottomView(Node *root) {
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        queue<pair<Node*, int>> q;
        map<int, int> mpp;
        
        q.push({root, 0});  // root is at level 0
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int level = it.second;
            
            // Always replace key line with new node data
            mpp[level] = node->data;
            
            if(node->left) {
                q.push({node->left, level-1});
            }
            
            if(node->right) {
                q.push({node->right, level+1});
            }
        }
        
        for(auto it: mpp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};