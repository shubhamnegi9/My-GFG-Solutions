//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    void bubbleSortRecursive(vector<int>& arr, int n) {
        if(n == 1) {
            return;
        }
        
        bool isSwapped = false;
        for(int j = 0; j <= n-2; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwapped = true;
            }
        }
        
        if(isSwapped == false)
            return;
        
        bubbleSortRecursive(arr, n-1);
    }
  
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        bubbleSortRecursive(arr, n);
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends