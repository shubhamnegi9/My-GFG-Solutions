//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C.= O(n^2)
    // S.C. = O(1)
    int inversionCount1(vector<int> &arr, int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] > arr[j])
                count++;
            }
        }
        
        return count;
    }
    
    int merge(vector<int> &arr, int low, int mid, int high) {
        int left = low, right = mid+1;
        int count = 0;
        vector<int> temp;
        
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                // Count inversion
                count += (mid-left+1);
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
        
        return count;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        // Base case
        if(low >= high)
            return 0;
        
        int count = 0;
        int mid = low + (high-low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    
    // Optimal Approach
    int inversionCount2(vector<int> &arr, int n) {
        return mergeSort(arr, 0, n-1);
    }
    
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        // Brute Force Approach
        // return inversionCount1(arr, n);
        
        // Optimal Approach
        return inversionCount2(arr, n);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends