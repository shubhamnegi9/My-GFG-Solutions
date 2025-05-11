//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n^2)
    void rotate1(vector<vector<int>>& mat, int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[n-1-j][i] = mat[i][j];   
            }
        }
        
        mat = ans;
    }
    
    // Optimal Approach
    // T.C. = O(n^2) + O(n)*O(n/2)
    // S.C. = O(1)
    void rotate2(vector<vector<int>>& mat, int n) {
        // Find transpose of matrix
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Reverse each column
        for(int j = 0; j < n; j++) {
            int start = 0;
            int mid = n/2;
            while(start < mid) {
                swap(mat[start][j], mat[n-start-1][j]);
                start++;
            }
        }
    }
    
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        // Brute Force Approach
        return rotate1(mat, n);
        
        // Optimal Approach
        // return rotate2(mat, n);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends