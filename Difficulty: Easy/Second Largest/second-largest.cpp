//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    // Brute Force Approach
    // T.C. = O(nlogn) + O(n)
    // S.C. = O(1)
    int getSecondLargest1(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int largest = arr[n-1];
        int sLargest = -1;
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] != largest) {
                sLargest = arr[i];
                break;
            }
        }
        
        return sLargest;
    }
    
    // Better Approach
    // T.C. = O(n) + O(n)
    // S.C. = O(1)
    int getSecondLargest2(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[0];
        int sLargest = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] > largest)
                largest = arr[i];
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > sLargest && arr[i] != largest)
                sLargest = arr[i];
        }
        
        return sLargest;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int getSecondLargest3(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[0];
        int sLargest = -1;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > largest) {
                sLargest = largest;
                largest = arr[i];
            } else if(arr[i] != largest && arr[i] > sLargest) {
                sLargest = arr[i];
            }
        }
        
        return sLargest;
    }
    
    int getSecondLargest(vector<int> &arr) {
        // Brute Force Approach
        // return getSecondLargest1(arr);
        
        // Better Approach
        // return getSecondLargest2(arr);
        
        // Optimal Approach
        return getSecondLargest3(arr);
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