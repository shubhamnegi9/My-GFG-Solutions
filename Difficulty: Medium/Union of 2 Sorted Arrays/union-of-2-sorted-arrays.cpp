class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        int n1 = a.size(), n2 = b.size();
        vector<int> result;
        
        while(i < n1 && j < n2) {
            if(a[i] <= b[j]) {
                if(result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
            } else {
                if(result.empty() || result.back() != b[j]) {
                    result.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(i < n1) {
            if(result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }
        
        while(j < n2) {
            if(result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }
        
        return result;
    }
};