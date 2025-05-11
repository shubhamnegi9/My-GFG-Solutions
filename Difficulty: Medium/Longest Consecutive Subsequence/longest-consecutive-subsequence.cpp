//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        int maxCount = 1, count = 0;

        if(n == 0)
            return 0;

        unordered_set<int> st(arr.begin(), arr.end());

        for(int i = 0; i < n; i++) {
            if(st.find(arr[i]-1) == st.end()) {
                int ele = arr[i];
                count = 1;
                while(st.find(ele+1) != st.end()) {
                    count++;
                    ele++;
                }
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends