// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size()-1;
        int minEle = INT_MAX;
        int index = -1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            // Search space from low to high is already sorted
            if(arr[low] <= arr[high]) {
                if(arr[low] < minEle) {
                    minEle = arr[low];
                    index = low;
                }
                break;
            }
            
            if(arr[low] <= arr[mid]) {
                if(arr[low] < minEle) {
                    minEle = arr[low];
                    index = low;
                }
                low = mid+1;
            } else {
                if(arr[mid] < minEle) {
                    minEle = arr[mid];
                    index = mid;
                }
                high = mid-1;
            }
        }
        
        return index;
    }
};
