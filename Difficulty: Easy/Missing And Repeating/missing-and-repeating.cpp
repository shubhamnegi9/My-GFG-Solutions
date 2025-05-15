//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    vector<int> findTwoElement1(vector<int>& arr, int n) {
        int missing = -1, repeating = -1;
        
        
        for(int num = 1; num <= n; num++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == num) {
                    count++;
                }
            }
            if(count == 2) {
                repeating = num;
            } else if(count == 0) {
                missing = num;
            }
            if(repeating != -1 && missing != -1) {
                break;
            }
        }
        
        return {repeating, missing};
    }
    
    // Better Approach
    // T.C. = O(2n)
    // S.C. = O(n) for map
    vector<int> findTwoElement2(vector<int>& arr, int n) {
        unordered_map<int, int> mpp;
        int missing = -1, repeating = -1;
        
        for(int& ele: arr) {
            mpp[ele]++;
        }
        
        for(int num = 1; num <= n; num++) {
            if(mpp[num] == 2) {
                repeating = num;
            } else if(mpp[num] == 0) {
                missing = num;
            }
            if(repeating != -1 && missing != -1) {
                break;
            }
        }
        
        return {repeating, missing};
    }
    
    // Optimal Approach using sum (Failing for large input for this problem)
    // T.C. = O(n)
    // S.C. = O(1) 
    vector<int> findTwoElement3(vector<int>& arr, int n) {
        long long Sn = (n*(n+1))/2;
        long long S2n = ((long long)n * (long long)(n+1) * (long long)(2*n+1))/6;
        
        long long S = 0, S2 = 0;
        
        for(int& ele: arr) {
            S += ele;
            S2 += ((long long)ele * (long long)ele);
        }
        
        long long diff = S - Sn;          // (R - M)
        long long add = (S2 - S2n)/diff;   // (R + M)
        
        long long repeating = (diff+add)/2;
        long long missing = repeating - diff;
        
        return {(int) repeating, (int) missing};
    }
    
    // Optimal Approach using XOR
    // T.C. = O(n)
    // S.C. = O(1) 
    vector<int> findTwoElement4(vector<int>& arr, int n) {
        int XR = 0;
        for(int i = 0; i < n; i++) {
            XR ^= arr[i];
            XR ^= (i+1);
        }
    
        // int bitPosition = 0;
        // while(1) {
        //     if(XR & (1 << bitPosition) != 0)
        //         break;
        //     bitPosition++;
        // }
        
        int rightmostSetBit = XR & ~(XR - 1);
    
        int zeroBit = 0, oneBit = 0;
        for(int i = 0; i < n; i++) {
            if((arr[i] & rightmostSetBit) != 0)
                oneBit ^= arr[i];
            else
                zeroBit ^= arr[i];
            
            
            if(((i+1) & rightmostSetBit) != 0)
                oneBit ^= (i+1);
            else
                zeroBit ^= (i+1);
        }
    

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == zeroBit)
                count++;
        }
    
        if(count == 0)
            return {oneBit, zeroBit};
        else    
            return {zeroBit, oneBit};
        
    }
    
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        
        // Brute Force Approach
        // return findTwoElement1(arr, n);
        
        // Better Approach
        // return findTwoElement2(arr, n);
        
        // Optimal Approach using sum
        // return findTwoElement3(arr, n);
        
        // Optimal Approach using XOR
        return findTwoElement4(arr, n);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends