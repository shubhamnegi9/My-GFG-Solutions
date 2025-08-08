// User function Template for C++

class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(R-L+1)
    // S.C. = O(1)
    int findXOR1(int l, int r) {
        int ans = 0;
        for(int i = l; i <= r; i++) {
            ans ^= i;
        }
        
        return ans;
    }
    
    int func(int n) {
        if(n%4 == 1) 
            return 1;
        else if(n%4 == 2)
            return n+1;
        else if(n%4 == 3)
            return 0;
        else
            return n;
    }
    
    // Optimal Approach
    // T.C. = O(1)
    // S.C. = O(1)
    int findXOR2(int l, int r) {
        return func(l-1) ^ func(r);
    }
    
    int findXOR(int l, int r) {
        // Brute Force Approach
        // return findXOR1(l, r);
        
        // Optimal Approach
        return findXOR2(l, r);
    }
};