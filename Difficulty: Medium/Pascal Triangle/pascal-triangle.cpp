//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    
    int findNcR(int n, int r) {
        long long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= (n-i);
            ans /= (i+1);
        }
        return (int) ans;
    }
  
    // Brute Force Approach
    // T.C. = O(n*r) = O(n*n) = O(n^2)
    // S.C. = O(1) for solving the problem
    vector<int> nthRowOfPascalTriangle1(int n) {
        vector<int> result;
        for(int r = 1; r <= n; r++) {
            result.push_back(findNcR(n-1, r-1));
        }
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1) for solving the problem
    vector<int> nthRowOfPascalTriangle2(int n) {
        vector<int> result;
        long long ans = 1;
        result.push_back(ans);
        
        for(int i = 1; i < n; i++) {
            ans *= (n-i);
            ans /= i;
            result.push_back((int) ans);
        }
        
        return result;
    }
    
    vector<int> nthRowOfPascalTriangle(int n) {
        // Brute Force Approach
        // return nthRowOfPascalTriangle1(n);
        
        // Optimal Approach
        return nthRowOfPascalTriangle2(n);
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends