// User function template for C++

class Solution {
  public:
    
    int countPainters(vector<int>& arr, int totalTime, int n) {
        int paintersCnt = 1;
        long long timeTaken = 0;
        
        for(int i = 0; i < n; i++) {
            if(timeTaken + arr[i] <= totalTime) {
                timeTaken += arr[i];
            } else {
                paintersCnt++;
                timeTaken = arr[i];
            }
        }
        
        return paintersCnt;
    }
  
    // Brute Force Approach
    // T.C. = O(max-sum+1)*O(n) for countPainters function
    // S.C. = O(1)
    int minTime1(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Impossible case
        // Each painter will not get atleast 1 board to paint
        if(k > n)
            return -1;
        
        int maxEle = *max_element(arr.begin(), arr.end());
        int sum = accumulate(arr.begin(), arr.end(), 0);
        for(int time = maxEle; time <= sum; time++) {
            if(countPainters(arr, time, n) == k)
                return time;
        }
        
        return -1;   
    }
    
    // Optimal Approach
    // T.C. = O(log(max-sum+1))*O(n) for countPainters function
    // S.C. = O(1)
    int minTime2(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Impossible case
        // Each painter will not get atleast 1 board to paint
        // if(k > n)
        //     return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(countPainters(arr, mid, n) > k) {
                low = mid+1;    // To decrease painters, we need to increase time taken by each painter
            } else {
                high = mid-1;   // To increase painters/ minimize the time (in case equal to k), we need to decrease time taken by each painter
            }
        }
        
        return low;
    }
    
    int minTime(vector<int>& arr, int k) {
        // Brute Force Approach
        // return minTime1(arr, k);
        
        // Optimal Approach
        return minTime2(arr, k);
    }
};