class Solution {
  public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(k+1) for set
    int longestKSubstr1(string &s, int k) {
        int n = s.length();
        int maxLen = -1;
        
        for(int i = 0; i < n; i++) {
            set<char> st;
            for(int j = i; j < n; j++) {
                st.insert(s[j]);
                if(st.size() == k) {
                    maxLen = max(maxLen, j-i+1);
                }
                else if(st.size() > k) {
                    break;
                }
            }
        }
        
        return maxLen;
    }
    
    // Better Approach
    // T.C. = O(2n)
    // S.C. = O(k+1) for set
    int longestKSubstr2(string &s, int k) {
        int n = s.length(), l = 0, r = 0, maxLen = -1;
        map<char, int> mpp;
        
        while(r < n) {
            mpp[s[r]]++;
            
            while(mpp.size() > k) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }
            
            if(mpp.size() == k) {
                maxLen = max(maxLen, r-l+1);
            }
            
            r++;
        }
        
        return maxLen;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(k+1) for set
    int longestKSubstr3(string &s, int k) {
        int n = s.length(), l = 0, r = 0, maxLen = -1;
        map<char, int> mpp;
        
        while(r < n) {
            mpp[s[r]]++;
            
            if(mpp.size() > k) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }
            
            if(mpp.size() == k) {
                maxLen = max(maxLen, r-l+1);
            }
            
            r++;
        }
        
        return maxLen;
    }
    
    int longestKSubstr(string &s, int k) {
        // Brute Force Approach
        // return longestKSubstr1(s, k);
        
        // Better Approach
        // return longestKSubstr2(s, k);
        
        // Optimal Approach
        return longestKSubstr3(s, k);
    }
};