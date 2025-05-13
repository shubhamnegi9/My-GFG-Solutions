//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(1)
    long subarrayXor1(vector<int> &arr, int k, int n) {
        long count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int XR = 0;
                for(int l = i; l <= j; l++) {
                    XR ^= arr[l];
                }
                if(XR == k) {
                    count++;
                }
            } 
        }
        
        return count;
    }
    
    // Better Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    long subarrayXor2(vector<int> &arr, int k, int n) {
        long count = 0;
        
        for(int i = 0; i < n; i++) {
            int XR = 0;
            for(int j = i; j < n; j++) {
                XR ^= arr[j];
                
                if(XR == k) {
                    count++;
                }
            } 
        }
        
        return count;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n) for map
    long subarrayXor3(vector<int> &arr, int k, int n) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int XR = 0;
        long count = 0;
        
        for(int& ele: arr) {
            XR ^= ele;
            count += mpp[XR^k];
            mpp[XR]++;
        }
        
        return count;
    }
    
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Brute Force Approach
        // return subarrayXor1(arr, k, n);
        
        // Better Approach
        // return subarrayXor2(arr, k, n);
        
        // Optimal Approach
        return subarrayXor3(arr, k, n);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends