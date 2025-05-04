//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int missingNum1(vector<int>& arr, int n) {
        int missing = -1;
        for(int num = 1; num <= n+1; num++) {
            bool found = false;
            for(int& ele: arr) {
                if(ele == num) {
                    found = true;
                    break;
                }
            }
            if(found == false) {
                missing = num;
            }
        }
        
        return missing;
    }
    
    // Better Approach
    // T.C. = O(n) + O(n)
    // S.C. = O(n)
    int missingNum2(vector<int>& arr, int n) {
        int missing = -1;
        unordered_map<int, int> mpp;
        
        for(int& ele: arr) {
            mpp[ele]++;
        }
        
        for(int num = 1; num <= n+1; num++) {
            if(mpp[num] == 0) {
                missing = num;
            }
        }
        
        return missing;
    }
    
    // Optimal Approach using sum
    // T.C. = O(n)
    // S.C. = O(1)
    int missingNum3(vector<int>& arr, int n) {
        int N = n+1;
        int sum = (N*(N+1))/2;
        int sum2 = 0;
        
        for(int& ele: arr) {
            sum2+= ele;
        }
        
        return sum-sum2;
    }
    
    // Optimal Approach using XOR
    // T.C. = O(n)
    // S.C. = O(1)
    int missingNum4(vector<int>& arr, int n) {
        int XOR = 0;
        
        for(int i = 0; i < n; i++) {
            XOR ^= arr[i];
            XOR ^= (i+1);
        }
        XOR ^= n+1;
        
        
        return XOR;
    }
    
    int missingNum(vector<int>& arr) {
        int n = arr.size();
        // Brute Force Approach
        // return missingNum1(arr, n);
        
        // Better Approach
        // return missingNum2(arr, n);
        
        // Optimal Approach using sum
        // return missingNum3(arr, n);
        
        // Optimal Approach using XOR
        return missingNum4(arr, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends