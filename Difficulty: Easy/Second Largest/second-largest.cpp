class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(nlogn) + O(n) = O(nlogn)
    // S.C. = O(1)
    int getSecondLargest1(vector<int> &arr) {
        int sLargest = -1;
        sort(arr.begin(), arr.end());
        int largest = arr.back();
        
        for(int i = arr.size()-1; i >= 0; i--) {
            if(arr[i] != largest) {
                sLargest = arr[i];
                break;
            }
        }
        
        return sLargest;
    }
    
    // Better Approach
    // T.C. = O(2n)
    // S.C. = O(1)
    int getSecondLargest2(vector<int> &arr) {
        int largest = arr[0];
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > largest) 
                largest = arr[i];
        }
        
        int sLargest = -1;
        for(int i = 1; i < n; i++) {
            if(arr[i] > sLargest && arr[i] != largest) {
                sLargest = arr[i];
            }
        }
        
        return sLargest;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int getSecondLargest3(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[0];
        int sLargest = -1;
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > largest) {
                sLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] != largest && arr[i] > sLargest) {
                sLargest = arr[i];
            }
        }
        
        return sLargest;
    }
    
    
    int getSecondLargest(vector<int> &arr) {
        // Brute Force Approach
        // return getSecondLargest1(arr);
        
        // Better Approach
        // return getSecondLargest2(arr);
        
        // Optimal Approach
        return getSecondLargest3(arr);
    }
};