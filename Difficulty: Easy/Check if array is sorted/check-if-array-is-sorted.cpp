class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    bool isSorted1(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[j] < arr[i])
                    return false;
            }
        }
        
        return true;
    }
    
    bool isSorted(vector<int>& arr) {
        // Brute Force Approach
        return isSorted1(arr);
    }
};