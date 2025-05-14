//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(nlogn) + O(2n)
    // S.C. = O(n) for returning answer
    vector<vector<int>> mergeOverlap1(vector<vector<int>>& arr, int n) {
        vector<vector<int>> mergedIntervals;
        
        // Sort intervals according to start times
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            int start = arr[i][0];
            int end = arr[i][1];
            
            // If current interval is already present in merged interval, move to next interval
            if(!mergedIntervals.empty() && end <= mergedIntervals.back()[1]) {
                continue;
            }
            
            for(int j = i+1; j < n; j++) {
                if(arr[j][0] <= end) {  // Current interval can be merged into previous interval
                    end = max(end, arr[j][1]);
                } else {    // Current interval cannot be merged into previous interval
                    break;
                }
            }
            
            mergedIntervals.push_back({start, end});
        }
        
        return mergedIntervals;
    }
    
    // Optimal Approach
    vector<vector<int>> mergeOverlap2(vector<vector<int>>& arr, int n) {
        vector<vector<int>> mergedIntervals;
        
        // Sort intervals according to start times
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            if(mergedIntervals.empty() || arr[i][0] > mergedIntervals.back()[1]) {
                // Current interval is first interval or cannot be merged to previous interval
                mergedIntervals.push_back(arr[i]);
            } else {
                // Current interval can be merged into previous interval
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], arr[i][1]);
            }
        }
        
        return mergedIntervals;
    }
    
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return mergeOverlap1(arr, n);
        
        // Optimal Approach
        return mergeOverlap2(arr, n);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends