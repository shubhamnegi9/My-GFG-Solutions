// User function template for C++

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(m*n) + O((m*n)*log(m*n)) for sorting 
    // S.C. = O(m*n) for array
    int median1(vector<vector<int>> &mat) {
        vector<int> arr;
        int m = mat.size(), n = mat[0].size();
        
        // Converting 2D matrix to 1D array
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                arr.push_back(mat[i][j]);
            }
        }
        
        // Sort all the elements of 1D array
        sort(arr.begin(), arr.end());
        
        // Element at (m*n)/2 is median
        return arr[(m*n)/2];
    }
    
    int upperBound(vector<int>& arr, int x, int n) {
        int low = 0, high = n-1;
        int ans = n;
        
        while(low <= high) {
            int mid = (low+high)/2;
            
            if(arr[mid] > x) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
    
    int countLessThanEqualToMid(vector<vector<int>> &mat, int x, int m, int n) {
        int count = 0;
        
        for(int i = 0; i < m; i++) {
            count += upperBound(mat[i], x, n);
        }
        
        return count;
    }
    
    // Optimal Approach
    // T.C. = O(log(max-min+1)) for bianry search * O(m*logn) for countLessThanEqualToMid()
    // S.C. = O(1)
    int median2(vector<vector<int>> &mat) {
        int low = INT_MAX, high = INT_MIN;
        int m = mat.size(), n = mat[0].size();
        
        for(int i = 0; i < m; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n-1]);
        }
        
        int req = (m*n)/2;
        while(low <= high) {
            int mid = (low+high)/2;
            
            int count = countLessThanEqualToMid(mat, mid, m, n);
            
            if(count <= req) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return low;
    }
    
    int median(vector<vector<int>> &mat) {
        // Brute Force Approach
        // return median1(mat);
        
        // Optimal Approach
        return median2(mat);
    }
};
