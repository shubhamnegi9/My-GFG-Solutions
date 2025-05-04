//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    bool twoSum1(vector<int>& arr, int target, int n) {
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] + arr[j] == target) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // Better Approach
    // T.C. = O(n)
    // S.C. = O(n)
    bool twoSum2(vector<int>& arr, int target, int n) {
        unordered_map<int, int> mpp;
        
        for(int i = 0; i < n; i++) {
            int num = target - arr[i];
            
            if(mpp.find(num) != mpp.end()) {
                return true;
            }
            
            mpp[arr[i]] = i;
        }
        
        return false;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn) + O(n/2)
    // S.C. = O(1)
    bool twoSum3(vector<int>& arr, int target, int n) {
        
        sort(arr.begin(), arr.end());
        
        int i = 0, j = n-1;
        
        while(i < j) {
            if(arr[i]+arr[j] == target) {
                return true;
            } else if(arr[i]+arr[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        
        return false;
    }
    
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        // Brute Force Approach
        // return twoSum1(arr, target, n);
        
        // Better Approach
        // return twoSum2(arr, target, n);
        
        // Optimal Approach
        return twoSum3(arr, target, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends