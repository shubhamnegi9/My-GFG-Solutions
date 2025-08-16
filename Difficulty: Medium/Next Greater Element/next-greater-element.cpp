class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n) for nge array
    vector<int> nextLargerElement1(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);     // Initialize all with -1, so that for last element, nge = -1 
        
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[j] > arr[i]) {
                    nge[i] = arr[j];
                    break;
                }
            }
        }
        
        return nge;
    }
    
    // Optimal Approach
    // T.C. = O(2n)
    // S.C. = O(n) for stack + O(n) for nge array
    vector<int> nextLargerElement2(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n, -1);
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return nge;
    }
    
    vector<int> nextLargerElement(vector<int>& arr) {
        // Brute Force Approach
        // return nextLargerElement1(arr);
        
        // Optimal Approach
        return nextLargerElement2(arr);
    }
};