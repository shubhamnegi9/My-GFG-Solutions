class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(nlogn)
    // S.C. = O(1)
    int largest1(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        return arr.back();
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = o(1)
    int largest2(vector<int> &arr) {
        int ans = arr[0];
        for(int &num: arr) {
            if(num > ans) {
                ans = num;
            }
        }
        
        return ans;
    }
    
    int largest(vector<int> &arr) {
        // Brute Force Approach
        // return largest1(arr);
        
        
        // Optimal Approach
        return largest2(arr);
    }
};
