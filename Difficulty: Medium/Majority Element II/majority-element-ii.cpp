//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    // Brute Force Approach
    // T.C. = O(n^2) + O(2log2)
    // S.C. = O(2) for ans vector
    vector<int> findMajority1(vector<int>& arr, int n) {
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == arr[i]) {
                    count++;
                    if(count > int(n/3)) {
                        // Only add if not already added in ans vector
                        if(ans.size() == 0 || ans[0] != arr[i]) {
                            ans.push_back(arr[i]);
                        }
                    }
                }
                // Once 2 majority elements found, break from further iterations
                if(ans.size() == 2)
                    break;
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    // Better Approach
    // T.C. = O(n) + O(2log2)
    // S.C. = O(2) for ans vector + O(n) for map
    vector<int> findMajority2(vector<int>& arr, int n) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        int mini = int(n/3)+1;
        
        for(int& ele: arr) {
            mpp[ele]++;
            if(mpp[ele] == mini) {
                ans.push_back(ele);
            }
            if(ans.size() == 2)
                break;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    // Optimal Approach
    // T.C. = O(2n) + O(2log2)
    // S.C. = O(2) for ans vector
    vector<int> findMajority3(vector<int>& arr, int n) {
        int count1 = 0, count2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            if(count1 == 0 && arr[i] != ele2) {
                ele1 = arr[i];
                count1 = 1;
            } else if(count2 == 0 && arr[i] != ele1) {
                ele2 = arr[i];
                count2 = 1;
            } else if(arr[i] == ele1) {
                count1++;
            } else if(arr[i] == ele2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        
        int cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        for(int &num: arr) {
            if(num == ele1) {
                cnt1++;
            }
            if(num == ele2) {
                cnt2++;
            }
        }
        
        if(cnt1 > int(n/3)) ans.push_back(ele1);
        if(cnt2 > int(n/3)) ans.push_back(ele2);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        // Brute Force Approach
        // return findMajority1(arr, n);
        
        // Better Approach
        // return findMajority2(arr, n);
        
        // Optimal Approach
        return findMajority3(arr, n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends