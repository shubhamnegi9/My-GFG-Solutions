//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        int left = l, right = mid+1;
        vector<int> temp;
        
        while(left <= mid && right <= r) {
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
        
        
        while(right <= r) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = l; i <= r; i++) {
            arr[i] = temp[i-l];
        }
    }
    
    // T.C. = O(nlogn)
    // S.C. = O(n) for temp vector
    void mergeSort(vector<int>& arr, int l, int r) {
        // base case
        if(l >= r) 
            return;
        
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends