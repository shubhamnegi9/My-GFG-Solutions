class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int inversionCount1(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] > arr[j])
                    count++;
            }    
        }
        
        return count;
    }
    
    int merge(vector<int>& arr, int low, int mid, int high) {
        int left = low, right = mid+1;
        vector<int> temp;
        int count = 0;
        
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                // Count of inversions
                count+= (mid-left+1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i-low];
        }
        
        return count;
    }    
    
    int mergeSort(vector<int>& arr, int low, int high) {
        // base case
        if(low >= high)
            return 0;
        
        int count = 0;
        int mid = low+(high-low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn)
    // S.C. = O(n) for temp vector
    int inversionCount2(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
    
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Brute Force Approach
        // return inversionCount1(arr);
        
        // Optimal Approach
        return inversionCount2(arr);
    }
};