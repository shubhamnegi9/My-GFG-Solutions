//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Iterative way
    int binarysearch1(vector<int> &arr, int k, int n) {
        int low = 0, high = n-1;
        int result = -1;    // Default value as -1
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(arr[mid] == k) {
                result = mid;   // Store in result
                high = mid-1;   // Move towards left to find smaller index
            } else if(k > arr[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return result;
    }
    
    // Recursive way
    int binarysearch2(vector<int> &arr, int low, int high, int k) {
        int result = -1;
        
        if(low > high)
            return result;
            
        int mid = low+(high-low)/2;
        if(arr[mid] == k) {
            result = mid;
            return binarysearch2(arr, low, mid-1, k);
        } else if(k > arr[mid]) {
            return binarysearch2(arr, mid+1, high, k);
        } else {
            return binarysearch2(arr, low, mid-1, k);
        }
    }
    
    int binarysearch(vector<int> &arr, int k) {
        int n = arr.size();
        // Iterative way
        return binarysearch1(arr, k, n);
        
        // Recursive way
        // return binarysearch2(arr, 0, n-1, k);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends