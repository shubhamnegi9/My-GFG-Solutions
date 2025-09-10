class Solution {
  public:
    // Brute Force Approach
    string smallestWindow1(string &s, string &p) {
        int n = s.length(), m = p.length();
        int sIndex = -1, minLen = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            vector<int> hashArr(256, 0);
            int count = 0;
            
            for(int j = 0; j < m; j++) {
                hashArr[p[j]]++;
            }
            
            for(int j = i; j < n; j++) {
                if(hashArr[s[j]] > 0) {
                    count++;
                }
                hashArr[s[j]]--;
                
                if(count == m) {
                    if(j-i+1 < minLen) {
                        minLen = j-i+1;
                        sIndex = i;
                    }
                }
            }
        }
        
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
    
    // Optimal Approach
    string smallestWindow2(string &s, string &p) {
        int n = s.length(), m = p.length();
        int l = 0, r = 0, count = 0, sIndex = -1, minLen = INT_MAX;
        
        vector<int> hashArr(256, 0);
        for(int i = 0; i < m; i++) {
            hashArr[p[i]]++;
        }
        
        while(r < n) {
            if(hashArr[s[r]] > 0) {
                count++;
            }
            hashArr[s[r]]--;
            
            while(count == m) {
                
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    sIndex = l;
                }
                
                hashArr[s[l]]++;
                if(hashArr[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
    
    string smallestWindow(string &s, string &p) {
        // Brute Force Approach
        // return smallestWindow1(s, p);
        
        // Optimal Approach
        return smallestWindow2(s, p);
    }
};