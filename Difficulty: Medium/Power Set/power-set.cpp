class Solution {
  public:
    // Using Bit Manipulation
    vector<string> AllPossibleStrings1(string s) {
        int n = s.length();
        int subsets = (1 << n);
        vector<string> ans;
        
        for(int num = 0; num < subsets; num++) {
            string str="";
            for(int i = 0; i < n; i++) {
                if(num & (1 << i)) {        // Checking if ith bit is set in num
                    str+=s[i];
                }
            }
            if(!str.empty()) {
                ans.push_back(str);     // Return only non-empty subsets
            }
        }
        
        sort(ans.begin(), ans.end());  // Return in lexicographical order
        
        return ans;
    }
    
    vector<string> AllPossibleStrings(string s) {
        // Using Bit Manipulation
        return AllPossibleStrings1(s);
    }
};