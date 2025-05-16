//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(1)
    int maxProduct1(vector<int> &arr, int n) {
        int maxProd = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int prod = 1;
                for(int k = i; k <= j; k++) {
                    prod *= arr[k];
                }
                maxProd = max(maxProd, prod);
            }
        }
        
        return maxProd;
    }
    
    // Better Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int maxProduct2(vector<int> &arr, int n) {
        int maxProd = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            int prod = 1;
            for(int j = i; j < n; j++) {
                prod *= arr[j];
                maxProd = max(maxProd, prod);
            }
        }
        
        return maxProd;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int maxProduct3(vector<int> &arr, int n) {
        int pref = -1, suff = -1;
        int maxProd = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            if(pref == 0)
                pref = 1;
            if(suff == 0)
                suff = 1;
            
            pref *= arr[i];
            suff *= arr[n-i-1];
            maxProd = max({maxProd, pref, suff});
        }
        
        return maxProd;
    }
    
    // Another Optimal Approach (Using modified kadane algo)
    // T.C. = O(n)
    // S.C. = O(1)
    int maxProduct4(vector<int> &arr, int n) {
        int maxProd = arr[0], currMax = arr[0], currMin = arr[0];
        
        for(int i = 1; i < n; i++) {
            int temp = max({arr[i], arr[i]*currMax, arr[i]*currMin});
            currMin = min({arr[i], arr[i]*currMax, arr[i]*currMin});
            currMax = temp;
            maxProd = max(maxProd, currMax);
        }
        
        return maxProd;
    }
    
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return maxProduct1(arr, n);
        
        // Better Approach
        // return maxProduct2(arr, n);
        
        // Optimal Approach
        // return maxProduct3(arr, n);
        
        // Another Optimal Approach (Using modified kadane algo)
        return maxProduct4(arr, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends