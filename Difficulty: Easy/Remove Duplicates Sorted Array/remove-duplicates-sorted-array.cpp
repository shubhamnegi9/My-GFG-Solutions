//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Brute Force
    // T.C. = O(nlogn)
    // S.C. = O(1)
    int removeDuplicates1(vector<int> &arr) {
        set<int> s(arr.begin(), arr.end());
        
        return s.size();
    }
    
    // Better Approach
    // T.C. = O(n)
    // S.C. = O(n)
    int removeDuplicates2(vector<int> &arr) {
        unordered_map<int, int> mpp;
        
        for(int& ele: arr) {
            mpp[ele]++;
        }
        
        return mpp.size();
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int removeDuplicates3(vector<int> &arr) {
        int n = arr.size();
        int i = 0;
        
        for(int j = 1; j < n; j++) {
            if(arr[j] != arr[i]) {
                arr[i+1] = arr[j];
                i++;
            }
        }
        
        return i+1;
    }
    
    
    int removeDuplicates(vector<int> &arr) {
        // Brute Force
        // return removeDuplicates1(arr);
        
        // Better Approach
        // return removeDuplicates2(arr);
        
        // Optimal Approach
        return removeDuplicates3(arr);
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
        int ans = ob.removeDuplicates(arr);
        for (int i = 0; i < ans; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends