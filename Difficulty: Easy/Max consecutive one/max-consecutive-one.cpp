//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // T.C. = O(2n)
    // S.C. = O(1)
    int maxConsecutiveCount(vector<int> &arr) {
        int count = 0;
        int maxCount1s = 0, maxCount0s = 0;
        
        for(int& ele: arr) {
            if(ele != 0) {
                count++;
                maxCount1s = max(maxCount1s, count);
            } else {
                count = 0;
            }
        }
        
        count = 0;
        
        for(int& ele: arr) {
            if(ele != 1) {
                count++;
                maxCount0s = max(maxCount0s, count);
            } else {
                count = 0;
            }
        }
        
        return max(maxCount1s, maxCount0s);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.maxConsecutiveCount(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends