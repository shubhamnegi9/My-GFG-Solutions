//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int countRevPairs1(int n, vector<int> arr) {
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] > 2*arr[j])
                    count++;
            }
        }
        
        return count;
    }
    
    // T.C. = O(n)
    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low, right = mid+1;
        vector<int> temp;
        
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i-low]; 
        }
    }
    
    // T.C. = O(n)
    int findReversePairCount(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int right = mid+1;
        
        for(int left = low; left <= mid; left++) {
            // Keep moving right pointer until arr[j] form reverse pair with arr[i] 
            // Cast nums[left] to long long and multiply arr[right] by 2LL 
            // to ensure the multiplication happens in the long long domain, avoiding overflow.
            while(right <= high && (long long) arr[left] > 2LL*arr[right]) {
                right++;
            }
            
            // Increment the count of reverse pair by (right-(mid+1))
            count += (right-(mid+1));
        }
        
        return count;
    }
    
    int mergeSort(vector<int>& arr, int low, int high)  {
        int count = 0;
        // base case
        if(low >= high) 
            return 0;
            
        int mid = low + (high-low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += findReversePairCount(arr, low, mid, high);
        merge(arr, low, mid, high);
        
        return count;
    }
    
    // Optimal Approach
    // T.C. = O(2n * O(logn)) = O(2n*logn)
    // S.C. = O(n) for temp vector in merge procedure
    int countRevPairs2(int n, vector<int> arr) {
        return mergeSort(arr, 0, n-1);
    }
    
    int countRevPairs(int n, vector<int> arr) {
        // Brute Force Approach
        // return countRevPairs1(n, arr);
        
        // Optimal Approach
        return countRevPairs2(n, arr);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends