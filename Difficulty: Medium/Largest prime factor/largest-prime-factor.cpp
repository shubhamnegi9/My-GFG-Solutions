class Solution {
  public:
    
    bool isPrime(int n) {
        if(n == 1)
            return false;
        
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0)
                return false;
        }
        
        return true;
    }
    
    // Brute Force Approach
    // T.C. = O(n * sqrt(n))
    // S.C. = O(no. of prime factors)
    int largestPrimeFactor1(int n) {
        vector<int> primeFactors;
        
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                if(isPrime(n)) {
                    primeFactors.push_back(i);
                }
            }
        }
        
        return primeFactors.back();
    }
    
    // Better Approach
    // T.C. = O(sqrt(n) * 2*sqrt(n)) approx. + O(mlogm), m = no. of prime factors
    // S.C. = O(no. of prime factors)
    int largestPrimeFactor2(int n) {
        vector<int> primeFactors;
        
        for(int i = 1; i*i <= n; i++) {
            if(n % i == 0) {
                if(isPrime(i)) {
                    primeFactors.push_back(i);
                }
                if((n/i) != i) {
                    if(isPrime(n/i)) {
                        primeFactors.push_back(n/i);
                    }
                }
            }
        }
        
        sort(primeFactors.begin(), primeFactors.end());
        
        return primeFactors.back();
    }
    
    // Optimal Approach
    // T.C. = O(sqrt(n) * logn)
    // S.C. = O(no. of prime factors)
    int largestPrimeFactor3(int n) {
        vector<int> primeFactors;
        
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) {
                primeFactors.push_back(i);
                
                while(n % i == 0)   // Divide n by i until n is divisible by i
                    n = n/i;
            }
        }
        
        if(n != 1) {
            primeFactors.push_back(n);
        }
        
        return primeFactors.back();
    }
  
    int largestPrimeFactor(int n) {
        // Brute Force Approach
        // return largestPrimeFactor1(n);
        
        // Better Approach
        // return largestPrimeFactor2(n);
        
        // Optimal Approach
        return largestPrimeFactor3(n);
    }
};