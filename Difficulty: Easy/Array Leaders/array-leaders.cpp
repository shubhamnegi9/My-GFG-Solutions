//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
    // Function to find the leaders in the array.
  public:
    
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n) for returning result
    vector<int> leaders1(vector<int>& arr, int n) {
        vector<int> result;
        
        for(int i = 0; i < n; i++) {
            int leader = arr[i];
            for(int j = i+1; j < n; j++) {
                if(arr[j] > arr[i]) {
                    leader = -1;
                    break;
                }
            }    
            if(leader != -1)
                result.push_back(leader);
        }
        
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(n) + O(n)
    // S.C. = O(n) for returning result
    vector<int> leaders2(vector<int>& arr, int n) {
        vector<int> result;
        result.push_back(arr[n-1]);
        int maxEle = arr[n-1];
        
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] >= maxEle) {
                result.push_back(arr[i]);
            }
            maxEle = max(maxEle, arr[i]);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return leaders1(arr, n);
        
        // Optimal Approach
        return leaders2(arr, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.leaders(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no leaders are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends