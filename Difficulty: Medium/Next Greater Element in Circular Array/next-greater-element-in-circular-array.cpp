class Solution {
  public:
    // Brute Force Approach
    vector<int> nextLargerElement1(vector<int> &arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < i+n; j++) {
                if(arr[j%n] > arr[i]) {
                    nge[i] = arr[j%n];
                    break;
                }
            }
        }
        
        return nge;
    }
    
    vector<int> nextLargerElement2(vector<int> &arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for(int i = 2*n-1; i >=0; i--) {
            while(!st.empty() && st.top() <= arr[i%n]) {
                st.pop();
            }
            
            if(i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }
            
            st.push(arr[i%n]);
        }
        
        return nge;
    }
    
    vector<int> nextLargerElement(vector<int> &arr) {
        // Brute Force Approach
        // return nextLargerElement1(arr);
        
        // Optimal Approach
        return nextLargerElement2(arr);
    }
};