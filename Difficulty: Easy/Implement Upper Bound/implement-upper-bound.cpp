// User function Template for C++
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;
        int index = arr.size();
        
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
};
