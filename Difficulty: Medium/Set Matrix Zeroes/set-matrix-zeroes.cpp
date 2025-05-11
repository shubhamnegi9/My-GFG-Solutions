//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Brute Force Approach using extra space
    // T.C. = O(m*n) * O(m+n)
    // S.C. = O(m*n) for temp matrix
    void setMatrixZeroes1(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> temp(mat);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    for(int k = 0; k < m; k++) {
                        temp[k][j] = 0;
                    }
                    for(int k = 0; k < n; k++) {
                        temp[i][k] = 0;
                    }
                }
            }
        }
        
        mat = temp;
    }
    
    // Brute Force Approach using extra space
    // T.C. = O(m*n) * O(m+n) + O(m*n)
    // S.C. = O(1) 
    void setMatrixZeroes2(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        
        int minEle = INT_MAX;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                minEle = min(minEle, mat[i][j]);
            }
        }
        
        int x = minEle-1;   // Distinct element not present in matrix
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    for(int k = 0; k < m; k++) {
                        if(mat[k][j] != 0) {
                            mat[k][j] = x;
                        }
                    }
                    for(int k = 0; k < n; k++) {
                        if(mat[i][k] != 0) {
                            mat[i][k] = x;
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == x) {
                    mat[i][j] = 0;
                }
            }
        }
        
    }
    
    // Better Approach
    void setMatrixZeroes3(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    mat[i][j] = 0;
                }
            }
        }
        
    }
    
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // Brute Force Approach using extra space
        // return setMatrixZeroes1(mat);
        
        // Brute Force Approach without using extra space
        // return setMatrixZeroes2(mat);
        
        // Better Approach
        return setMatrixZeroes3(mat);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends