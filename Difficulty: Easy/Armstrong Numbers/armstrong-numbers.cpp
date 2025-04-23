//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int count = 0;
        int temp = n;
        while(temp > 0) {
            count++;
            temp /= 10;
        }
        
        int sum = 0;
        int temp2 = n;
        while(temp2) {
            int digit = temp2 % 10;
            sum += pow(digit, count);
            temp2 /= 10;
        }
        
        return sum == n;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        bool flag = ob.armstrongNumber(n);
        if (flag) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends