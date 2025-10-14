// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int temp = arr.back();
        int n = arr.size();
        
        for(int i = n-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }
};