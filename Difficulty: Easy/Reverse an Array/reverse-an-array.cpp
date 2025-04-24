//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Approach 1: Using recursion + 2 pointer
    void reverseArrayUsing2Pointer(vector<int> &arr, int i, int j) {
        if(i >= j) 
            return;
        
        swap(arr[i], arr[j]);
        reverseArrayUsing2Pointer(arr, i+1, j-1);
    }
    
    // Approach 2: Using recursion + 1 pointer
    void reverseArrayUsing1Pointer(vector<int> &arr, int i, int n) {
        if(i >= n/2)
            return;
        
        swap(arr[i], arr[n-i-1]);
        reverseArrayUsing1Pointer(arr, i+1, n);
    }
  
    void reverseArray(vector<int> &arr) {
        // Approach 1: Using recursion + 2 pointer
        int i = 0;
        int j = arr.size()-1;
        // reverseArrayUsing2Pointer(arr, i, j);
        
        
        // Approach 2: Using recursion + 1 pointer
        reverseArrayUsing1Pointer(arr, i, arr.size());
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends