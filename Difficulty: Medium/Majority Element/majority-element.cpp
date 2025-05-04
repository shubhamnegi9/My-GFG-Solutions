//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int majorityElement1(vector<int>& arr, int n) {
        for(int i = 0; i < n; i++) {
            int count = 0;
            int currEle = arr[i];
            for(int j = 0; j < n; j++) {
                if(arr[j] == currEle) {
                    count++;
                }
            }
            
            if(count > n/2)
                return currEle;
        }
        
        return -1;
    }
    
    // Better Approach
    // T.C. = O(n) + O(n)
    // S.C. = O(n)
    int majorityElement2(vector<int>& arr, int n) {
        unordered_map<int, int> mpp;
        
        for(int& ele: arr) {
            mpp[ele]++;
        }
        
        for(auto it: mpp) {
            if(it.second > n/2) {
                return it.first;
            }
        }
        
        return -1;
    }
    
    // Optimal Approach
    // T.C. = O(n) + O(n)
    // S.C. = O(1)
    int majorityElement3(vector<int>& arr, int n) {
        int ele = 0, count = 0;
        
        for(int i = 0; i < n; i++) {
            if(count == 0) {
                count = 1;
                ele = arr[i];
            } else if(arr[i] == ele) {
                count++;
            } else {
                count--;
            }
        }
        
        int cnt = 0;
        for(int &num: arr) {
            if(num == ele) {
                cnt++;
            }
        }
        
        return (cnt > n/2) ? ele : -1;
        
    }
    
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return majorityElement1(arr, n);
        
        // Better Approach
        // return majorityElement2(arr, n);
        
        // Optimal Approach
        return majorityElement3(arr, n);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends