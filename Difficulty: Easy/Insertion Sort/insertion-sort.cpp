//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void recursiveInsertionSort(vector<int>& arr, int i) {
        int n = arr.size();
        
        if(i >= n)
            return;
        
        int j = i;
        
        while(j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
        
        recursiveInsertionSort(arr, i+1);
    }
  
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        recursiveInsertionSort(arr, 0);
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
        obj.insertionSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends