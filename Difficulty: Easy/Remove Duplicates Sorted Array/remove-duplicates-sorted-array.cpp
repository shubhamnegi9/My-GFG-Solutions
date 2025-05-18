//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n) for inseting in set + O(n) for copying from set to arr
    // S.C. = O(n) for set
    int removeDuplicates1(vector<int> &arr) {
        set<int> st(arr.begin(), arr.end());
        
        int index = 0;
        for(auto it: st) {
            arr[index] = it;
            index++;
        }
        
        return index;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int removeDuplicates2(vector<int> &arr) {
        int n = arr.size();
        int i = 0;
        
        for(int j = 0; j < n; j++) {
            if(arr[j] != arr[i]) {
                arr[i+1] = arr[j];
                i++;
            }
        }
        
        return i+1;
    }
    
    int removeDuplicates(vector<int> &arr) {
        // Brute Force Approach
        // return removeDuplicates1(arr);
        
        // Optimal Approach
        return removeDuplicates2(arr);
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