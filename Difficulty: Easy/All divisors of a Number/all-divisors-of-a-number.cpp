class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    void print_divisors1(int n) {
        for(int i = 1; i <= n; i++) {
            if(n % i == 0)
                cout << i << " ";
        }
        cout << endl;
    }
    
    // Optimal Approach
    // T.C. = O(sqrt(n)) + O(mlogm). m = no. of divisors
    // S.C. = O(1) for solving problem, O(m) for returning answer
    void print_divisors2(int n) {
        vector<int> arr;
        for(int i = 1; i*i <= n; i++) {
            if(n % i == 0) {
                arr.push_back(i);
                
                if((n/i) != i)
                    arr.push_back(n/i);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        for(int& num: arr) {
            cout << num << " ";
        }
    }
    
    void print_divisors(int n) {
        // Brute Force Approach
        // print_divisors1(n);
        
        // Optimal Approach
        print_divisors2(n);
    }
};