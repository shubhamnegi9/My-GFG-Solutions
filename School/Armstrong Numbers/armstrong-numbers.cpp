//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int count = 0;
    	int temp = n;
    	while(temp) {
    		count++;
    		temp /= 10;
    	}
    	temp = n;
    	int sum = 0;
    	while(temp) {
    		int digit = temp%10;
    		sum += pow(digit, count);
    		temp/= 10;
    	}
    
    	return (sum == n)? "Yes" : "No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends