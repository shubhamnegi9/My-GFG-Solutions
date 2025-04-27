//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    
    // Brute Force Approach
    // T.C. = O(n) + O(x) + O(n-x) = O(2n)
    // S.C. = O(x) = O(n)
    void pushZerosToEnd1(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                temp.push_back(arr[i]);
            }
        }
        
        int nz = temp.size();
        for(int i = 0; i < nz; i++) {
            arr[i] = temp[i];
        }
        
        for(int i = nz; i < n; i++) {
            arr[i] = 0;
        }
    }
    
    // Optimal Approach
    // T.C. = O(x) + O(n-x) = O(n)
    // S.C. = O(1)
    void pushZerosToEnd2(vector<int>& arr) {
        int n = arr.size();
        
        int i = -1;
        for(int j = 0; j < n; j++) {
            if(arr[j] == 0) {
                i = j;
                break;
            }
        } 
        
        if(i == -1)
            return;     // No zero elements in array
        
        for(int j = i+1; j < n; j++) {
            if(arr[j] != 0) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
    }
    
    void pushZerosToEnd(vector<int>& arr) {
        // Brute Force Approach
        // return pushZerosToEnd1(arr);
        
        // Optimal Approach
        return pushZerosToEnd2(arr);
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
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends