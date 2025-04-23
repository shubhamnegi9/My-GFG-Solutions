//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int reverseDigits(int n) {
        int reversed = 0;
        while(n) {
            int digit = n % 10;
            reversed = reversed*10 + digit;
            n /= 10;
        }
        
        return reversed;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.reverseDigits(n);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends