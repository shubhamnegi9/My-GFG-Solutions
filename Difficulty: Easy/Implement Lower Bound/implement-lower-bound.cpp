//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Using Binary Search
    // T.C. = O(logn)
    int lowerBound1(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n-1;
        int result = n;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(arr[mid] < target) {
                low = mid+1;
            } else {
                result = mid;
                high = mid-1;
            }
        }
        
        return result;
    }
    
    // Using STL function
    int lowerBound2(vector<int>& arr, int target) {
        return lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        
    }
    
    int lowerBound(vector<int>& arr, int target) {
        // Using Binary Search
        return lowerBound1(arr, target);
        
        // Using STL function
        // return lowerBound2(arr, target);
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.lowerBound(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends