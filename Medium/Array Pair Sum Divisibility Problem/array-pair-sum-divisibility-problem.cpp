//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPairBrute(vector<int> nums, int k) {
        int n = nums.size();
        bool isFound = false;
        // If odd length, then all pairs cannot be formed
        if(n % 2 == 1)
            return false;
        
        // Map for storing visited indexes
        unordered_map<int, bool> mpp;
        for(int i = 0; i < n; i++) {
            mpp[i] = false;
        }
        
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                // If elements are not visited and their sum is divisible by k
                if(!mpp[i] && !mpp[j] && (nums[i] + nums[j]) % k == 0) {
                    mpp[i] = true;
                    mpp[j] = true;
                    isFound = true;
                    break;
                }
            }
            // If for any element, pair is not found
            // then return false
            if(!isFound)
                return false;
        }
        
        return true;
    }
    
    bool canPairOptimal(vector<int> nums, int k) {
        /*
            Logic:
            If (a+b)%k = 0 and a%k = r1 and b%k = r2
            then r1 + r2 = k
        */
    
        set<int> st;
        for(auto ele: nums) {
            int r1 = ele%k;
            int r2 = k-r1;
            if(st.find(r2) != st.end()) {
                // Pair found. Erase r2
                st.erase(r2);
            }
            else if(r1 == 0 && st.find(0) != st.end()) {    // corner case
                // Pair found. Erase 0
                st.erase(0);
            }
            else {
                // Add r1 in set for making pair
                st.insert(r1);
            }
        }
        
        // If set becomes empty, then all pairs are found
        if(st.size() == 0)
            return true;
        
        return false;
 
        
    }
    
    bool canPair(vector<int> nums, int k) {
        // Brute Force:
        // return canPairBrute(nums, k);
        // Optimal:
        return canPairOptimal(nums, k);
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends