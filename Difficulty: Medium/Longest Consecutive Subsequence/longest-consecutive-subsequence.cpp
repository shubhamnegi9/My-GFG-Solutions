//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool isFoundUsingLS(vector<int>& arr, int x, int n) {
        for(int i = 0; i < n; i++) {
            if(arr[i] == x)
                return true;
        }
        return false;
    } 
    
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int longestConsecutive1(vector<int>& arr, int n) {
        int maxCount = INT_MIN;

        for(int i = 0; i < n; i++) {
            int x = arr[i];
            int count = 1;
            while(isFoundUsingLS(arr, x+1, n)) {
                count++;
                x++;
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
    
    bool isFoundUsingBS(vector<int>& arr, int x, int low, int high) {
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == x) {
                return true;
            } else if(arr[mid] < x) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return false;
    } 
    
    // Better Brute Force Approach
    // T.C. = O(nlogn) for sorting + O(n*logn) = O(nlogn)
    // S.C. = O(1)
    int longestConsecutive2(vector<int>& arr, int n) {
        int maxCount = INT_MIN;
    
        sort(arr.begin(), arr.end());
    
        for(int i = 0; i < n; i++) {
            int x = arr[i];
            int count = 1;
            while(isFoundUsingBS(arr, x+1, 0, n-1)) {
                count++;
                x++;
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
    
    // Better Approach
    // T.C. = O(nlogn) for sorting + O(n) = O(nlogn) overall
    // S.C. = O(1)
    int longestConsecutive3(vector<int>& arr, int n) {
        int maxCount = 1, lastSmallest = INT_MIN, count = 0;
        
        if(n == 0)
            return INT_MIN;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            if(lastSmallest + 1 == arr[i]) {
                count++;
                lastSmallest = arr[i];
            } else {
                count = 1;
                lastSmallest = arr[i];
            }
            
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
    
    // Optimal Approach
    int longestConsecutive4(vector<int>& arr, int n) {
        int maxCount = 1, count = 0;
        
        if(n == 0)
            return INT_MIN;
        
        unordered_set<int> st(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            int x = arr[i];
            if(st.find(x-1) == st.end()) {  // This is first element of sequence
                count = 1;
                while(st.find(x+1) != st.end()) {   // Increase count until next element is found
                    count++;
                    x++;
                }
                maxCount = max(maxCount, count);
            }
        }
        
        return maxCount;
    }
    
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return longestConsecutive1(arr, n);
        
        // Better Brute Force Approach
        // return longestConsecutive2(arr, n);
        
        // Better Approach
        // return longestConsecutive3(arr, n);
        
        // Optimal Approach
        return longestConsecutive4(arr, n);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends