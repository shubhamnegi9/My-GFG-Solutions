//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> sieveOfEratosthenes(int n) {
        
        vector<bool> primes(n+1, true);
        
        for(int i = 2; i*i <= n; i++) {
            if(primes[i]) {
                for(int j = i*i; j <= n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        
        vector<int> result;
        for(int i = 2; i <= n; i++) {
            if(primes[i]) {
                result.push_back(i);
            }
        }
        
        return result;
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
        vector<int> primes = ob.sieveOfEratosthenes(n);
        for (auto prime : primes) {
            cout << prime << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends