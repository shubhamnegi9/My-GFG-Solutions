// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int temp = n;
        int sum = 0;
        
        while(temp > 0) {
            int digit = temp%10;
            sum += digit*digit*digit;
            temp/=10;
        }
        
        return sum == n;
    }
};