class Solution {
  public:
    // Brute force approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    long subarrayXor1(vector<int> &arr, int k, int n) {
        long count = 0;
        
        for(int i = 0; i < n; i++) {
            int XR = 0;
            for(int j = i; j < n; j++) {
                XR ^= arr[j];
                
                if(XR == k)
                    count++;
            }
        }
        
        return count;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n)
    long subarrayXor2(vector<int> &arr, int k, int n) {
        long count = 0, XR = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            XR ^= arr[i];
            count += mpp[XR ^ k];
            mpp[XR]++;
        }
        
        return count;
    }
    
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        // Brute force approach
        // return subarrayXor1(arr, k, n);
        
        // Optimal Approach
        return subarrayXor2(arr, k, n);
    }
};