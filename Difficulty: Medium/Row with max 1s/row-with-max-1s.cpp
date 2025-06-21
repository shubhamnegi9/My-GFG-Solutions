// User function template for C++
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(m*n)
    // S.C. = O(1)
    int rowWithMax1sBrute(vector<vector<int>> &arr) {
        int m = arr.size(), n = arr[0].size();
        int maxCount = 0;
        int index = -1;
        
        for(int i = 0; i < m; i++) {
            int countOf1s = 0;
            for(int j = 0; j < n; j++) {
                countOf1s += arr[i][j];
            }
            if(countOf1s > maxCount) {
                maxCount = countOf1s;
                index = i;
            }
        }
        
        return index;
    }
    
    int lowerBound(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = n;
        
        while(low <= high) {
            int mid = (low+high)/2;
            
            if(arr[mid] >= x) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
    
    // Better Approach
    // T.C. = O(m*log(n))
    // S.C. = O(1)
    int rowWithMax1sBetter(vector<vector<int>> &arr) {
        int m = arr.size(), n = arr[0].size();
        int maxCount = 0;
        int index = -1;
        
        for(int i = 0; i < m; i++) {
            int countOf1s = m - lowerBound(arr[i], 1);
            if(countOf1s > maxCount) {
                maxCount = countOf1s;
                index = i;
            }
        }
        
        return index;
    }
    
    // Optimal Approach
    int rowWithMax1sOptimal(vector<vector<int>> &arr) {
        int m = arr.size(), n = arr[0].size();
        int index = -1;
        int i = 0, j = n-1;
        
        while(i < m && j >= 0) {
            // If the current value is 0, move down to the next row
            if(arr[i][j] == 0) {
                i++;
            } 
            // Else if the current value is 1, update ans and
            // move to the left column
            else {
                index = i;
                j--;
            }
        }
        
        return index;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        // Brute Force Approach
        // return rowWithMax1sBrute(arr);
        
        // Better Approach
        // return rowWithMax1sBetter(arr);
        
        // Optimal Approach
        return rowWithMax1sOptimal(arr);
        
    }
};