class Solution {
  public:
    // Method for finding power to n using power exponentiation
    // T.C. = O(logn)
    int findPow(int num, int n) {
        int ans = 1;
        
        while(n > 0) {
            if(n % 2 == 1) {
                ans *= num;
                n -= 1;
            } else {
                num = num*num;
                n /= 2;
            }
        }
        
        return ans;
    }
  
    // Brute Force Approach
    // T.C. = O(m*logn)
    int nthRoot1(int n, int m) {
        for(int i = 1; i <= m; i++) {
            int pow = findPow(i, n);
            if(pow == m) {
                return i;
            } else if(pow > m) {
                break;
            }
        }
        
        return -1;
    }
    
    int nthRoot(int n, int m) {
        // Brute Force Approach
        return nthRoot1(n, m);
    }
};