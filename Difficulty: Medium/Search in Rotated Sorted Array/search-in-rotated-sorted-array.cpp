class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int search1(vector<int>& arr, int key) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == key)
                return i;
        }
        return -1;
    }
    
    // Optimal Approach
    // T.C. = O(logn)
    // S.C. = O(1)
    int search2(vector<int>& arr, int key) {
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(arr[mid] == key) {
                return mid;
            } 
            
            
            if(arr[low] <= arr[mid]) {
                // Left part of mid is sorted
                if(key >= arr[low] && key <= arr[mid]) {    // Key exists in left part
                    high = mid-1;       // Eliminate right half
                } else {    
                    low = mid+1;        // Eliminate left half
                }
            } else {
                // Right part of mid is sorted
                if(key >= arr[mid] && key <= arr[high]) { // Key exists in right part
                    low = mid+1;        // Eliminate left half
                } else {
                    high = mid-1;       // Eliminate right half
                }
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& arr, int key) {
        // Brute Force Approach
        // return search1(arr, key);
        
        // Optimal Approach
        return search2(arr, key);
    }
};