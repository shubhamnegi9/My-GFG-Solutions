//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    // Brute Force Approach
    // T.C. = O(n^4) * O(log(no of unique quads))
    // S.C. = O(no of unique quads) for set + O(no of unique quads) for vector
    vector<vector<int> > fourSum1(vector<int> &arr, int target, int n) {
        set<vector<int>> st;
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    for(int l = k+1; l < n; l++) {
                        sum = arr[i]+arr[j];
                        sum += arr[k];
                        sum += arr[l];
                        if((int)sum == target) {
                            vector<int> ans = {arr[i], arr[j], arr[k], arr[l]};
                            sort(ans.begin(), ans.end());
                            st.insert(ans);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> result(st.begin(), st.end());
        return result;
        
    }
    
    // Better Approach
    // T.C. = O(n^3) * O(log(no of unique quads))
    // S.C. = O(no of unique quads) for set + O(no of unique quads) for vector + O(n) for hashSet
    vector<vector<int> > fourSum2(vector<int> &arr, int target, int n) {
        set<vector<int>> st;
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                set<int> hashSet;
                for(int k = j+1; k < n; k++) {
                    sum = arr[i]+arr[j];
                    sum += arr[k];
                    int fourth = target - sum;
                    if(hashSet.find(fourth) != hashSet.end()) {
                        vector<int> ans = {arr[i], arr[j], arr[k], fourth};
                        sort(ans.begin(), ans.end());
                        st.insert(ans);
                    }
                
                    hashSet.insert(arr[k]);
                }
            }
        }
        
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(n^2) * O(n)
    // S.C. = O(no of unique quads) for vector 
    vector<vector<int> > fourSum3(vector<int> &arr, int target, int n) {
        
        vector<vector<int>> result;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && arr[i] == arr[i-1])
                continue;
                
            for(int j = i+1; j < n; j++) {
                if(j != i+1 && arr[j] == arr[j-1]) 
                    continue;
                
                int k = j+1, l = n-1;
                
                while(k < l) {
                    long long sum = arr[i]+arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    
                    if(sum < target) {
                        k++;
                    } else if(sum > target) {
                        l--;
                    } else {
                        result.push_back({arr[i], arr[j], arr[k], arr[l]});
                        k++;
                        l--;
                        
                        while(k < l && arr[k] == arr[k-1]) k++;
                        while(k < l && arr[l] == arr[l+1]) l--;
                    }
                }
            }
        }
        
        return result;
        
    }
    
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        int n = arr.size();
        
        // Brute Force Approach
        // return fourSum1(arr, target, n);
        
        // Better Approach
        // return fourSum2(arr, target, n);
        
        // Optimal Approach
        return fourSum3(arr, target, n);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(arr, d);
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << endl;
        }
        if (ans.empty()) {
            cout << -1 << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends