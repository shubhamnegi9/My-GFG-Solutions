class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
        visited[node] = 1;
        result.push_back(node);
        
        for(auto it: adj[node]) {
            if(!visited[it]) {
                DFS(it, adj, visited, result);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> result;
        int start = 0;
        
        DFS(start, adj, visited, result);
        
        return result;
    }
};