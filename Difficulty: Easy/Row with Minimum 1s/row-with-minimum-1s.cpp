class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        int index = 0;
        int m = mat.size(), n = mat[0].size();
        int minCount = n;
        
        for(int i = 0; i < m; i++) {
            int countOf1s = 0;
            for(int j = 0; j < n; j++) {
                countOf1s += mat[i][j];
            }
            if(countOf1s < minCount) {
                minCount = countOf1s;
                index = i;
            }
        }
        
        return index+1;     // Need to return the row number
    }
};