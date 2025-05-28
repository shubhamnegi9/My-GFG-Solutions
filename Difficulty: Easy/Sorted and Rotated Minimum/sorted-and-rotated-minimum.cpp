class Solution {
  public:
    // Brute Force 
    // T.C. = O(n)
    // S.C. = O(1)
    int findMin1(vector<int>& arr) {
        int minEle = INT_MAX;
        
        for(int&ele: arr) {
            minEle = min(minEle, ele);
        }
        
        return minEle;
    }
    
    // Optimal Approach
    // T.C. = O(logn)
    // S.C. = O(1)
    int findMin2(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        int minEle = INT_MAX;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            // Optimization step
            if(arr[low] <= arr[high]) {
                minEle = min(minEle, arr[low]);
                break;
            }
            
            if(arr[low] <= arr[mid]) {
                // Left part is sorted
                minEle = min(minEle, arr[low]);
                low = mid+1;
            } else {
                // Right part is sorted
                minEle = min(minEle, arr[mid]);
                high = mid-1;
            }
        }
        
        return minEle;
    }
    
    int findMin(vector<int>& arr) {
        // Brute Force 
        // return findMin1(arr);
        
        // Optimal Approach
        return findMin2(arr);
    }
};