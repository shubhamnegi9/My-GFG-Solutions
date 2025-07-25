class Solution {
  public:
    
    void bitManiputaion1(int num, int i) {
        string b = "";
        int temp = num;
        while(temp) {
            if(temp%2 == 0) 
                b+='0';
            else
                b+='1';
            temp/=2;
        }
        reverse(b.begin(), b.end());
        int len = b.length();
        char res = ((i <= len) ? b[len-i] : '0');                // i is 1 based indexing
        cout << res << " ";
    }
    
    void bitManipulation(int num, int i) {
        // Get ith bit
        // Brute Force
        // bitManiputaion1(num, i);
        
        // Optimal
        int n1 = num;
        cout << ((n1 & (1 << (i-1))) >> (i-1)) << " ";     // i is 1 based indexing
        
        // Set ith bit
        int n2 = num;
        cout << (n2 | (1 << (i-1))) << " ";     // i is 1 based indexing
        
        // Clear ith bit
        int n3 = num;
        cout << (n3 & ~(1 << (i-1)));           // i is 1 based indexing
    }
};