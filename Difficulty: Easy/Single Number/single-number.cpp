//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int getSingle1(vector<int>& arr) {
        int n = arr.size();
        int singleEle = -1;
        
        for(int i = 0; i < n; i++) {
            int currEle = arr[i];
            int count = 0;
            for(int& ele: arr) {
                if(ele == currEle) {
                    count++;
                }
            }
            if(count%2 == 1) {
                singleEle = currEle;
                break;
            }
        }
        
        return singleEle;
    }
    
    // Better Approach
    // T.C. = O(2n)
    // S.C. = O(n)
    int getSingle2(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int singleEle = -1;
        
        for(int& ele: arr) {
            mpp[ele]++;
        }
        
        for(auto it: mpp) {
            if(it.second % 2 == 1) {
                singleEle = it.first;
                break;
            }
        }
        
        return singleEle;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int getSingle3(vector<int>& arr) {
        int XOR = 0;
        for(int& ele: arr) {
            XOR ^= ele;
        }
        
        return XOR;
    }
    
    int getSingle(vector<int>& arr) {
        // Brute Force Approach
        // return getSingle1(arr);
        
        // Better Approach
        // return getSingle2(arr);
        
        // Optimal Approach
        return getSingle3(arr);
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
        int res = obj.getSingle(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends