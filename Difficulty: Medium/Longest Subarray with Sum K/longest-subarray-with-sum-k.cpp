//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(1)
    int longestSubarray1(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = 0;
                for(int l = i; l <= j; l++) {
                    sum += arr[l];
                }
                if(sum == k) {
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        
        return maxLen;
    }
    
    // Better Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int longestSubarray2(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += arr[j];
                if(sum == k) {
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        
        return maxLen;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n)
    int longestSubarray3(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(sum == k) {
                maxLen = max(maxLen, i+1);
            }
            
            if(mpp.find(sum-k) != mpp.end()) {
                maxLen = max(maxLen, i - mpp[sum-k]);
            }
            
            if(mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }
        
        return maxLen;
    }
    
    int longestSubarray(vector<int>& arr, int k) {
        // Brute Force Approach
        // return longestSubarray1(arr, k);
        
        // Better Approach
        // return longestSubarray2(arr, k);
        
        // Optimal Approach
        return longestSubarray3(arr, k);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends