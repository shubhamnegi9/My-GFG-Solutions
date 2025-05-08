//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(string& s, set<string>& st, string& ans, vector<int>& visited, int n) {
        // Base case
        if(ans.length() == n) {
            st.insert(ans);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                ans+=s[i];
                visited[i] = 1;
                solve(s, st, ans, visited, n);
                
                // Reset values on backtracking
                visited[i] = 0;
                ans.pop_back();
            }
        }
    }
  
    vector<string> findPermutation(string &s) {
        int n = s.length();
        set<string> st;
        string ans="";
        vector<int> visited(n, 0);
        solve(s, st, ans, visited, n);
        vector<string> result(st.begin(), st.end());
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends