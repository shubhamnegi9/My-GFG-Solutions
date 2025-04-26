//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    // Brute Force
    // T.C. = O(nlogn)
    // S.C. = O(1)
    int largest1(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        return arr.back();
    }
  
    int largest(vector<int> &arr) {
        // Brute Force 
        return largest1(arr);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.largest(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends