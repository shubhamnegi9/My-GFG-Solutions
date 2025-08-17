
class Solution {
  public:
    // Brute Force Approach
    // T.C. O(Q * n)
    // S.C. = O(Q) for returning answer
    int countNextLargest(vector<int> &arr, int ind) {
        int n = arr.size();
        int count = 0;
        for(int i = ind+1; i < n; i++) {
            if(arr[i] > arr[ind])
                count++;
        }
        return count;
    }
    
    vector<int> count_NGE1(vector<int> &arr, vector<int> &indices) {
        vector<int> ans;
        for(int ind: indices) {
            ans.push_back(countNextLargest(arr, ind));
            
        }
        
        return ans;
    }
    
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // Brute Force Approach
        return count_NGE1(arr, indices);
        
    }
};