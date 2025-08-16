// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        stack<string> st;
        
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {     // operand
                
                string str(1, s[i]);    // Converting char to string
                st.push(str);
            }
            else {                  // operator
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                string ans = s[i] + s2 + s1;
                st.push(ans);
            }
        }
        
        return st.top();
    }
};