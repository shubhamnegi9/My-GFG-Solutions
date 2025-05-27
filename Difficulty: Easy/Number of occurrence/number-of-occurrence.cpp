class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int countFreq1(vector<int>& arr, int target) {
        int count = 0;
        for(int& ele: arr) {
            if(ele == target)
                count++;
        }
        return count;
    }
    
    int findLowerBound(vector<int>& arr, int target) {
        int index = arr.size();
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(arr[mid] >= target) {
                index = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return index;
    }
    
    int findUpperBound(vector<int>& arr, int target) {
        int index = arr.size();
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(arr[mid] > target) {
                index = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return index;
    }
    
    // Optimal Approach 1
    // T.C. = 2*O(logn)
    // S.C. = O(1)
    int countFreq2(vector<int>& arr, int target) {
        int ubIndex = findUpperBound(arr, target);
        int lbIndex = findLowerBound(arr, target);
        
        // Exception case
        if(lbIndex == arr.size() || arr[lbIndex] != target)
            return 0;
        
        return ((ubIndex-1) - lbIndex + 1);
    }
  
    int countFreq(vector<int>& arr, int target) {
        // Brute Force Approach
        // return countFreq1(arr, target);
        
        // Optimal Approach 1
        return countFreq2(arr, target);
        
    }
};
