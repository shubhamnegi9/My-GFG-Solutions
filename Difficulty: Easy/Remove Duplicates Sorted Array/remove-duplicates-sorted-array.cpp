class Solution {
  public:
    // Approach using set
    vector<int> removeDuplicates1(vector<int> &arr) {
        set<int> st(arr.begin(), arr.end());
        vector<int> ans(st.begin(), st.end());
        
        return ans;
    }
    
    // Approach without using set
    vector<int> removeDuplicates2(vector<int> &arr) {
        int prev = -1;
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != prev) {
                prev = arr[i];
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
    
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // return removeDuplicates1(arr);
        
        return removeDuplicates2(arr);
    }
};