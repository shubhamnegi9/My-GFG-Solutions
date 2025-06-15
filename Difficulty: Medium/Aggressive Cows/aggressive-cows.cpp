// User function Template for C++

class Solution {
  public:
    
    bool canPlaceCows(vector<int> &stalls, int dist, int k, int n) {
        int cntCows = 1, last = stalls[0];
        
        for(int i = 1; i < n; i++) {
            if(stalls[i] - last >= dist) {
                cntCows++;
                last = stalls[i];   // We need to find distance between consecutive cows
            }
            
            if(cntCows >= k)
                return true;    // Possible to arrange all the k cows
        }
        
        return false;
    }
    
    // Brute Force Approach
    // T.C. = O(nlogn) for sorting + O(n) * O(max-min) = O(n^2)
    // S.C. = O(1)
    int aggressiveCows1(vector<int> &stalls, int k) {
        int n = stalls.size();
        
        // Sort the stalls based on position
        sort(stalls.begin(), stalls.end());
        
        int maxRange = stalls[n-1]-stalls[0];
        for(int i = 0; i < maxRange; i++) {
            if(canPlaceCows(stalls, i, k, n)) {
                continue;
            } else {
                return i-1;     // Return the last possible consecutive distance
            }
        }
        
        return -1;
    }
    
    // Optimal Approach
    // T.C. of Optimal Approach = O(nlogn) for sorting + O(n) * O(log(max-min))
    // S.C. of Optimal Approach = O(1)
    int aggressiveCows2(vector<int> &stalls, int k) {
        int n = stalls.size();
        
        // Sort the stalls based on position
        sort(stalls.begin(), stalls.end());
        
        int low = 1, high = stalls[n-1]-stalls[0];
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(canPlaceCows(stalls, mid, k, n)) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return high;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // Brute Force Approach
        // return aggressiveCows1(stalls, k);
        
        // Optimal Approach
        return aggressiveCows2(stalls, k);
    }
};