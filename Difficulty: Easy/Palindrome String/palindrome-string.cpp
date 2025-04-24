//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to check if a string is a palindrome.
    
    bool checkPalindrome(int i, string& s) {
        int n = s.length();
        if(i >= n/2)
            return true;
        
        if(s[i] != s[n-i-1])
            return false;
        
        return checkPalindrome(i+1, s);
    }
    
    bool isPalindrome(string& s) {
        return checkPalindrome(0, s);
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        string s;
        cin >> s; // Read the string

        Solution ob; // Create an instance of Solution
        if (ob.isPalindrome(s)) {
            cout << "true"; // Print true if palindrome
        } else {
            cout << "false"; // Print false if not a palindrome
        }
        cout << "\n~\n"; // Print newline after each result
    }

    return 0;
}

// } Driver Code Ends