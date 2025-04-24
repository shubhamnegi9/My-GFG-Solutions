//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void reverse(vector<int>& arr, int i, int n) {
        if(i >= n/2)
            return;
        
        swap(arr[i], arr[n-i-1]);
        reverse(arr, i+1, n);
    }
    
    void reverseArray(vector<int> &arr) {
        int i = 0;
        int n = arr.size();
        reverse(arr, i, n);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends