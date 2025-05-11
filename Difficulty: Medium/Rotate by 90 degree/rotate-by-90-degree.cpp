//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */

// Brute Force Approach
// T.C. = O(n^2)
// S.C. = O(n^2)
void rotate1(vector<vector<int> >& mat, int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[j][n-i-1] = mat[i][j];
        }
    }
    
    mat = ans;
}

// Optimal Approach
// T.C. = O(n^2) + O(n^2)
// S.C. = O(1)
void rotate2(vector<vector<int> >& mat, int n) {
    // Find Transpose
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    // Reverse each row
    for(int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

void rotate(vector<vector<int> >& mat) {
    int n = mat.size();
    
    // Brute Force Approach
    // return rotate1(mat, n);
    
    // Optimal Approach
    return rotate2(mat, n);
}



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends