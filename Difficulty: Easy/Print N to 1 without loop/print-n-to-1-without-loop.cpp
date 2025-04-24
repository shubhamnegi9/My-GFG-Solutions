//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void printNto1(int N) {
        if(N < 1)
            return;
        
        cout << N << " ";
        printNto1(N-1);
    }
    
    // Using backtracking
    void printNto1(int i, int N) {
        if(i > N)
            return;
        
        printNto1(i+1, N);
        cout << i << " ";
    }
  
    void printNos(int N) {
        
        // Approach 1
        // printNto1(N);
        
        // Approach 2
        printNto1(1, N);
    }
};


//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends