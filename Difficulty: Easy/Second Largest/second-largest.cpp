//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(nlogn) + O(n)
    // S.C. = O(1)
    int getSecondLargest1(vector<int> &arr, int n) {
        sort(arr.begin(), arr.end());
        int largest = arr.back();
        
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] != largest)
                return arr[i];
        }
        
        return -1;
    }
    
    // Better Approach
    // T.C. = O(n) + O(n)
    // S.C. = O(1)
    int getSecondLargest2(vector<int> &arr, int n) {
        int largest = -1;
        
        for(int& ele: arr) {
            largest = max(largest, ele);
        }
        
        int secLargest = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] > secLargest && arr[i] != largest)
                secLargest = arr[i];
        }
        
        return secLargest;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int getSecondLargest3(vector<int> &arr, int n) {
        int largest = -1, secLargest = -1;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > largest) {
                secLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] > secLargest && arr[i] != largest)
                secLargest = arr[i];
        }
        
        return secLargest;
    }
    
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return getSecondLargest1(arr, n);
        
        // Better Approach
        // return getSecondLargest2(arr, n);
        
        // Optimal Approach
        return getSecondLargest3(arr, n);
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends