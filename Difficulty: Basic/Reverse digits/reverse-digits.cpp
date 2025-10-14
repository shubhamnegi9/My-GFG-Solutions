class Solution {
  public:
    int reverseDigits(int n) {
        int reversed = 0;
        while(n > 0) {
            int r = n%10;
            reversed = reversed*10 + r;
            n/=10;
        }
        
        return reversed;
    }
};