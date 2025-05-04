//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(1)
    int maxSubarraySum1(vector<int> &arr, int n) {
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = 0;
                for(int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
    
    // Better Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int maxSubarraySum2(vector<int> &arr, int n) {
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += arr[j];
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
    
    // Optimal Approach using Kadane's Algo
    // T.C. = O(n)
    // S.C. = O(1)
    int maxSubarraySum3(vector<int> &arr, int n) {
        int maxSum = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            maxSum = max(maxSum, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        return maxSum;
    }
    
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return maxSubarraySum1(arr, n);
        
        // Better Approach
        // return maxSubarraySum2(arr, n);
        
        // Optimal Approach using Kadane's Algo
        return maxSubarraySum3(arr, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}
// } Driver Code Ends