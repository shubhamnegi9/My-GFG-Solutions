//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(mlogm) + O(nlogn) + O(m+n)
    // S.C. = O(m+n) extra space for set + O(m+n) for returning answer
    vector<int> findUnion1(vector<int> &a, vector<int> &b) {
        set<int> st;
        
        for(int& ele: a) {
            st.insert(ele);
        }
        
        for(int& ele: b) {
            st.insert(ele);
        }
        
        vector<int> unionArr;
        for(auto ele: st) {
            unionArr.push_back(ele);
        }
        
        return unionArr;
    }
    
    // Optimal Approach
    // T.C. = O(m+n)
    // S.C. = O(m+n) for returning answer
    vector<int> findUnion2(vector<int> &a, vector<int> &b) {
        vector<int> unionArr;
        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        
        while(i < m && j < n) {
            if(a[i] <= b[j]) {
                if(unionArr.size() == 0 || a[i] != unionArr.back()) {
                    unionArr.push_back(a[i]);
                }
                i++;
            } else {
                if(unionArr.size() == 0 || b[j] != unionArr.back()) {
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(i < m) {
            if(unionArr.size() == 0 || a[i] != unionArr.back()) {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        
        while(j < n) {
            if(unionArr.size() == 0 || b[j] != unionArr.back()) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
        
        return unionArr;
    }
 
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Brute Force Approach
        // return findUnion1(a, b);
        
        // Optimal Approach
        return findUnion2(a, b);

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends