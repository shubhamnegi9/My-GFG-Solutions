class Solution {
  public:
    int countStudents(vector<int>& arr, int pages, int n) {
        int studentCnt = 1;
        long long pagesAssigned = 0;
        
        for(int i = 0; i < n; i++) {
            if(pagesAssigned+arr[i] <= pages) {
                pagesAssigned += arr[i];
            } else {
                studentCnt++;
                pagesAssigned = arr[i];
            }
        }
        
        return studentCnt;
    }
  
    // Brute Force Approach
    // T.C. = O(sum-max+1) * O(n) for countStudents function
    // S.C. = O(1)
    int findPages1(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Impossible case
        if(k > n)
            return -1;
        
        int maxEle = *max_element(arr.begin(), arr.end());
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        for(int pages = maxEle; pages <= sum; pages++) {
            if(countStudents(arr, pages, n) == k)
                return pages;
        }
        
        return -1;
    }
    
    // Optimal Approach
    // T.C. = O(log(sum-max+1)) * O(n) for countStudents function
    // S.C. = O(1)
    int findPages2(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Impossible case
        if(k > n)
            return -1;
            
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(countStudents(arr, mid, n) > k) {
                low = mid+1;   // To decrease student, we need to increase max pages assigned
            } else {
                high = mid-1;  // To increase student/ minimize the pages (in case equal to k), we need to decrease max pages assigned
            }
        }
        
        return low;
    }
    
    int findPages(vector<int> &arr, int k) {
        // Brute Force Approach
        // return findPages1(arr, k);
        
        // Optimal Approach
        return findPages2(arr, k);
    }
};