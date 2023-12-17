//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int totalDigits(long long int n){
        long long int total = 0;
        for(int i = 1; i <= n; i*=10) {
            total += (n-i+1);
        }
        
        return total;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.totalDigits(n) << endl;
    }
    return 0;
}

// } Driver Code Ends