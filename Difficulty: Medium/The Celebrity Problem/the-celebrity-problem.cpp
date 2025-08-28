class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2) + O(n)
    // S.C. = O(2n)
    int celebrity1(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<int> knowMe(n, 0);
        vector<int> iKnow(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(knowMe[i] == n && iKnow[i] == 1) {
                return i;
            }
        }
        
        return -1;
    }
    
    // Optimal Approach
    // T.C. = O(2n)
    // S.C. = O(1)
    int celebrity2(vector<vector<int>>& mat) {
        int n = mat.size();
        
        int top = 0, bottom = n-1;
        
        while(top < bottom) {
            if(mat[top][bottom] == 1) {
                top++;
            } 
            else if(mat[bottom][top] == 1) {
                bottom--;
            }
            else {
                top++;
                bottom--;
            }
        }
        
        if(top > bottom) {
            return -1;
        }    
        
        // (top == bottom)
        for(int i = 0; i < n; i++) {
            if(i == top) continue;  // skiping dialonal elements
            if(mat[top][i] == 0 && mat[i][top] == 1) {
                continue;
            }else {
                return -1;
            }
        }
        
        return top;
    }
    
    int celebrity(vector<vector<int>>& mat) {
        // Brute Force Approach
        // return celebrity1(mat);
        
        // Optimal Approach
        return celebrity2(mat);
    }
};