// User function Template for C++

class Solution {
  public:
    
    bool isPrime(int n) {
        if(n == 1)
            return false;
        
        for(int i = 2; i*i <= n; i++) {
            if(n%i == 0)
                return false;
        }
        
        return true;
    }
  
    // Brute Force Approach
    // T.C. = O(R-L+1) * O(sqrt(n))
    // S.C. = O(1)
    int countPrimes1(int L, int R) {
        int count = 0;
        for(int i = L; i <= R; i++) {
            if(isPrime(i)) {
                count++;
            }
        }
        
        return count;
    }
    
    vector<int> getSieve(int n) {
        vector<int> primes(n+1);    // Declare primes array of size (n+1)
        
        for(int i = 2; i <= n; i++) {
            primes[i] = 1;
        }
        
        for(int i = 2; i*i <= n; i++) {
            if(primes[i]) {
                for(int j = i*i; j <= n; j+=i) {
                    primes[j] = 0;
                }
            }
        }
        
        return primes;
    }
    
    // Optimal Approach
    // T.C. = O(RloglogR) + O(R-L+1)
    // S.C. = O(R) for primes array
    int countPrimes2(int L, int R) {
        int count = 0;
        vector<int> primes = getSieve(R);
        
        for(int i = L; i <= R; i++) {
            if(primes[i]) {
                count++;
            }
        }
        
        return count;
    }
    
    int countPrimes(int L, int R) {
        // Brute Force Approach
        // return countPrimes1(L, R);
        
        // Optimal Approach
        return countPrimes2(L, R);
    }
};