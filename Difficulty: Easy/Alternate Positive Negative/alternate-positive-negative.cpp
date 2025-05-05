//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> positives, negatives;
        
        for(int& ele: arr) {
            if(ele >= 0)
                positives.push_back(ele);
            else
                negatives.push_back(ele);
        }
        
        int m = positives.size(), n = negatives.size();
        
        if(m > n) {
            for(int i = 0; i < n; i++) {
                arr[2*i] = positives[i];
                arr[2*i+1] = negatives[i];
            }
            
            int index = 2*n;
            for(int i = n; i < m; i++) {
                arr[index] = positives[i];
                index++;
            }
        } else {
            for(int i = 0; i < m; i++) {
                arr[2*i] = positives[i];
                arr[2*i+1] = negatives[i];
            }
            
            int index = 2*m;
            for(int i = m; i < n; i++) {
                arr[index] = negatives[i];
                index++;
            }
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends