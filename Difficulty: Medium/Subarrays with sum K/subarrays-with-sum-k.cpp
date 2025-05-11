//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(1)
    int countSubarrays1(vector<int> &arr, int k, int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = 0;
                for(int l = i; l <= j; l++) {
                    sum += arr[l];
                }
                if(sum == k)
                    count++;
            }
        }
        
        return count;
    }
    
    // Better Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int countSubarrays2(vector<int> &arr, int k, int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += arr[j];
                
                if(sum == k)
                    count++;
            }
        }
        
        return count;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n) for map
    int countSubarrays3(vector<int>& arr, int k, int n) {
        unordered_map<int, int> mpp;
        int count = 0, preSum = 0;
        
        mpp[0] = 1;     // There will be one emp
        
        for(int i = 0; i < n; i++) {
            preSum += arr[i];
            
            if(mpp.find(preSum-k) != mpp.end()) {
                count += mpp[preSum-k];
            }
            
            mpp[preSum]++;
        }
        
        return count;
    }
    
    int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Brute Force Approach
        // return countSubarrays1(arr, k, n);
        
        // Better Approach
        // return countSubarrays2(arr, k, n);
        
        // Optimal Approach
        return countSubarrays3(arr, k, n);
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends