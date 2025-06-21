class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n1+n2)
    // S.C. = O(n1+n2)
    int kthElement1(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        vector<int> merged;
        int i = 0, j = 0;
        
        while(i < n1 && j < n2) {
            if(a[i] < b[j]) {
                merged.push_back(a[i]);
                i++;
            } else {
                merged.push_back(b[j]);
                j++;
            }
        }
        
        while(i < n1) {
            merged.push_back(a[i]);
            i++;
        }
        
        while(j < n2) {
            merged.push_back(b[j]);
            j++;
        }
        
        return merged[k-1];     // kth element in merged array 
    }
    
    // Better Approach
    // T.C. = O(n1+n2)
    // S.C. = O(1)
    int kthElement2(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0, cnt = 0, ele = 0;
        
        while(i < n1 && j < n2) {
            if(a[i] < b[j]) {
                if(cnt == k-1)
                    ele = a[i];
                cnt++;
                i++;
            } else {
                if(cnt == k-1)
                    ele = b[j];
                cnt++;
                j++;
            }
        }
        
        while(i < n1) {
            if(cnt == k-1)
                ele = a[i];
            cnt++;
            i++;
        }
        
        while(j < n2) {
            if(cnt == k-1)
                ele = b[j];
            cnt++;
            j++;
        }
        
        return ele;
    }
    
    // Optimal Approach
    // T.C. = O(log(min(n1, n2)))
    // S.C. = O(1)
    int kthElement3(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        int n = n1+n2;
        
        if(n1 > n2) {
            kthElement3(b, a, k);
        }
        
        int low = max(0, k-n2), high = min(n1, k);
        
        while(low <= high) {
            int mid1 = (low+high)>>1;
            int mid2 = k-mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1-1 >= 0)
                l1 = a[mid1-1];
            if(mid2-1 >= 0)
                l2 = b[mid2-1];
            if(mid1 < n1)
                r1 = a[mid1];
            if(mid2 < n2)
                r2 = b[mid2];
            
            if(l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if(l1 > r2)
                high = mid1-1;
            else
                low = mid1+1;
        }
        
        return 0;
    }
    
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // Brute Force Approach
        return kthElement1(a, b, k);
        
        // Better Approach
        // return kthElement2(a, b, k);
        
        // Optimal Approach
        // return kthElement3(a, b, k);
    }
};