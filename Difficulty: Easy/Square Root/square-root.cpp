// Function to find square root
// x: element to find square root
class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int floorSqrt1(int n) {
        int ans = 1;
        
        for(int i = 1; i <= n; i++) {
            if(i*i <= n) {
                ans = i;
            } else {
                break;
            }
        }
        
        return ans;
    }
    
    // Optimal Approach
    // T.C. = O(logn)
    // S.C. = O(1)
    int floorSqrt2(int n) {
        int low = 1, high = n;
        
        while(low <= high) {
            long long mid = low+(high-low)/2;
            long long val = mid* mid;
            if(val <= n) {
                low = mid+1;    
            } else {
                high = mid-1;
            }
        }
        
        return high;    // high will be storing max possible square root
    }
    
    int floorSqrt(int n) {
        // Brute Force Approach
        // return floorSqrt1(n);
        
        // Optimal Approach
        return floorSqrt2(n);
    }
};