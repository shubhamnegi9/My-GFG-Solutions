class Solution {
  public:
    // Brute Force Approach
    int setKthBit1(int n, int k) {
        // Convert to binary
        string b = "";
        while(n) {
            if(n%2==0)
                b+='0';
            else
                b+='1';
            n/=2;
        }
        reverse(b.begin(), b.end());
        
        // Make kth bit from right as 1
       int len = b.length();
       b[len-k-1] = '1';
       
       // Convert to decimal
       int p = 1, res = 0;
       for(int i = b.length()-1; i >= 0; i--) {
           if(b[i] == '1')
                res += p;
            
            p *= 2;
       }
       
       return res;
    }
  
    int setKthBit(int n, int k) {
        // Brute Force Approach
        // return setKthBit1(n, k);
        
        // Optimal Approach
        return (n | (1 << k));
    }
};
