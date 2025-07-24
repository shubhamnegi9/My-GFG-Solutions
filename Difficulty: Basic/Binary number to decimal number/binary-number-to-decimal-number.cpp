class Solution {
  public:
    int binaryToDecimal(string &b) {
        int len = b.length();
        int p = 1;
        int res = 0;
        
        for(int i = len-1; i >= 0; i--) {
            if(b[i] == '1') {
                res += p;
            }    
            
            p *= 2;
        }
        
        return res;
    }
};