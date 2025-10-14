class Solution {
  public:
    
    void printDivisors1(int n) {
        for(int i = 1; i <= n; i++) {
            if(n%i == 0)
                cout << i << " ";
        }
        cout << endl;
    }
    
    void printDivisors2(int n) {
        vector<int> ans;
        for(int i = 1; i*i <= n; i++) {
            if(n%i == 0) {
                ans.push_back(i);
                if(i != (n/i)) {
                    ans.push_back(n/i);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        for(int& num: ans) {
            cout << num << " ";
        }
    }
    
    void print_divisors(int n) {
        // Brute Force
        // printDivisors1(n);
        
        // Optimal Approach
        printDivisors2(n);
    }
};