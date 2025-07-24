class Solution {
  public:
    // Brute Force Approach
    bool checkKthBit1(int n, int k) {
        string b = "";
        while(n) {
            if(n%2 == 0)
                b += '0';
            else
                b += '1';
            n/=2;    
        }
        reverse(b.begin(), b.end());
        
        int len = b.length();
        return b[len-k-1] == '1' ? true : false;
    }
    
    bool checkKthBit(int n, int k) {
        // Brute Force Approach
        // return checkKthBit1(n, k);
        
        // Optimal Approach using left shift
        // return ((n & (1 << k)) == 1) ? true : false;
        
        // Optimal Approach using right shift
        return (((n >> k) & 1) == 1) ? true : false;
    }
};