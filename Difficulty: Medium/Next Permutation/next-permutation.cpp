//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void solve(vector<int>& arr, set<vector<int>>& st, vector<int>& ans, vector<int>& visited, int n) {
        // Base Case
        if(ans.size() == n) {
            st.insert(ans);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                ans.push_back(arr[i]);
                visited[i] = 1;
                solve(arr, st, ans, visited, n);
                
                // Reset values on backtracking
                visited[i] = 0;
                ans.pop_back();
            }
        }
    }
    
    // Brute Force Approach
    // T.C. = O(n*n!) for generating all permutations + O(n!) for searching given permutation 
    // S.C. = O(n) for ans vector + O(n) for visited vector + O(n!) for set
    void nextPermutation1(vector<int>& arr, int n) {
        set<vector<int>> st;
        vector<int> ans;
        vector<int> visited(n, 0);
        solve(arr, st, ans, visited, n);
        
        auto it = st.find(arr);
        if(it != st.end()) {
            auto nextIt = next(it);
            if(nextIt != st.end()) {
                arr = *nextIt;
            } else {
                arr = *st.begin();
            }
        }
    }
    
    // Better Approach using STL 
    // T.C. = O(n)
    void nextPermutation2(vector<int>& arr, int n) {
        next_permutation(arr.begin(), arr.end());
    }
  
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // nextPermutation1(arr, n);
        
        // Better Approach
        nextPermutation2(arr, n);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends