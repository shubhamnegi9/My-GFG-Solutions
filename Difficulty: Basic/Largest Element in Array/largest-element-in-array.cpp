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
    // Brute Force Approach
    // T.C. = O(nlogn)
    // S.C. = O(1)
    int largest1(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        return arr.back();
    }
  
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int largest2(vector<int> &arr) {
        int maxEle = arr[0];
        for(int& num: arr) {
            if(num > maxEle) {
                maxEle = num;
            }
        }
        return maxEle;
    }
    
    int largest(vector<int> &arr) {
        // Brute Force Approach
        // return largest1(arr);
        
        // Optimal Approach
        return largest2(arr);
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