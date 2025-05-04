//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(nlogn)
    // S.C. = O(1)
    bool arraySorted1(vector<int>& arr, int n) {
        vector<int> sortedArr = arr;
        
        sort(sortedArr.begin(), sortedArr.end());
        
        return sortedArr == arr;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    bool arraySorted2(vector<int>& arr, int n) {

        for(int i = 0; i < n-1; i++) {
            if(arr[i] > arr[i+1])
                return false;
        }
        
        return true;
    }
    
    bool arraySortedOrNot(vector<int>& arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return arraySorted1(arr, n);
        
        // Optimal Approach
        return arraySorted2(arr, n);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(nums);
        cout << (ans ? "true" : "false") << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends