class Solution {
  public:
    // Brute Force Approach using linear search
    // T.C. = O(n)
    // S.C. = O(1)
    vector<int> find1(vector<int>& arr, int x) {
        int n = arr.size();
        int first = -1, last = -1;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == x) {
                if(first == -1) 
                    first = i;
                last = i;
            }
        }
        
        return {first, last};
    }
    
    int findLowerBound(vector<int>& arr, int x) {
        int index = arr.size();
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(arr[mid] >= x) {
                index = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return index;
    }
    
    int findUpperBound(vector<int>& arr, int x) {
        int index = arr.size();
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(arr[mid] > x) {
                index = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return index;
    }
    
    // Optimal Approach 1 by finding lower and upper bound
    // T.C. = 2*O(log(n))
    // S.C. = O(1)
    vector<int> find2(vector<int>& arr, int x) {
        int lbIndx = findLowerBound(arr, x);
        int ubIndx = findUpperBound(arr, x);
        
        // Exception case
        if(lbIndx == arr.size() || arr[lbIndx] != x) {
            return {-1, -1};
        }
        
        return {lbIndx, ubIndx-1};
    }
    
    int findFirstIndex(vector<int>& arr, int x) {
        int index = -1;
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(arr[mid] == x) {
                index = mid;
                high = mid-1;
            } else if(arr[mid] < x) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return index;
    }
    
    int findLastIndex(vector<int>& arr, int x) {
        int index = -1;
        int low = 0, high = arr.size()-1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            
            if(arr[mid] == x) {
                index = mid;
                low = mid+1;
            } else if(arr[mid] < x) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return index;
    }
    
    // Optimal Approach 2 by plain binary search
    // T.C. = 2*O(log(n))
    // S.C. = O(1)
    vector<int> find3(vector<int>& arr, int x) {
        int first = findFirstIndex(arr, x);
        
        if(first == -1)
            return {-1, -1};
        
        int last = findLastIndex(arr, x);
        return {first, last};
    }
    
    vector<int> find(vector<int>& arr, int x) {
        // Brute Force Approach using linear search
        return find1(arr, x);
        
        // Optimal Approach 1 by finding lower and upper bound
        // return find2(arr, x);
        
        // Optimal Approach 2 by plain binary search
        // return find3(arr, x);
    }
};