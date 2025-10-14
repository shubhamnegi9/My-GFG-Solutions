class Solution {
  public:
    int gcd(int a, int b) {
        int gcd = 1;
        while(a > 0 && b > 0) {
            if(a > b) 
                a = a % b;
            else
                b = b % a;
        }
        
        if(a == 0) 
            gcd = b;
        else if(b == 0)
            gcd = a;
        
        return gcd;
    }
};
