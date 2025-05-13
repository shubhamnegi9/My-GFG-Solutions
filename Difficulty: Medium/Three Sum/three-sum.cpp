//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class Solution {
  public:
  
    // Brute Force Approach
    // T.C. = O(n^3) * O(log(no of unique triplet))
    // S.C. = O(no of unique triplet) for set + O(no of unique triplet) for vector
    vector<vector<int>> triplets1(vector<int> &arr, int n) {
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(arr[i]+arr[j]+arr[k] == 0) {
                        vector<int> ans = {arr[i], arr[j], arr[k]};
                        sort(ans.begin(), ans.end());
                        st.insert(ans);
                    }
                }
            }
        }
        
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
    
    // Better Approach
    // T.C. = O(n^2) * O(log(no of unique triplet))
    // S.C. = O(no of unique triplet) for set + O(no of unique triplet) for vector + O(n) for hashSet
    vector<vector<int>> triplets2(vector<int> &arr, int n) {
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++) {
            set<int> hashSet;
            for(int j = i+1; j < n; j++) {
                int third = -(arr[i]+arr[j]);
                if(hashSet.find(third) != hashSet.end()) {
                    vector<int> ans = {arr[i], arr[j], third};
                    sort(ans.begin(), ans.end());
                    st.insert(ans);
                }
                hashSet.insert(arr[j]);
            }
        }
        
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn) for sorting + O(n^2) 
    // S.C. = O(no of unique triplet) for vector
    vector<vector<int>> triplets3(vector<int> &arr, int n) {
        vector<vector<int>> result;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {            // O(n)
            if(i > 0 && arr[i] == arr[i-1])
                continue;
            
            int j = i+1, k = n-1;
            while(j < k) {                      // O(n)
                int sum = arr[i]+arr[j]+arr[k];
                
                if(sum < 0) {
                    j++;
                } else if(sum > 0) {
                    k--;
                } else {
                    result.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                    while(j < k && arr[j] == arr[j-1]) j++;
                    while(j < k && arr[k] == arr[k+1]) k--;
                }
            }
        }
        
        return result;
    }
    
    vector<vector<int>> triplets(vector<int> &arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return triplets1(arr, n);
        
        // Better Approach
        // return triplets2(arr, n);
        
        // Optimal Approach
        return triplets3(arr, n);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();

        Solution obj;
        vector<vector<int>> res = obj.triplets(arr);
        if (res.size() == 0) {
            cout << endl;
        } else
            Matrix::print(res);
    }
}

// } Driver Code Ends