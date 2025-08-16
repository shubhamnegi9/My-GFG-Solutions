// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack<string> st;
        
        for(int i = s.length()-1; i >= 0; i--) {
            if(isalpha(s[i])) {     // operand
            
                string str(1, s[i]);    // Converting char to string
                st.push(str);
            }
            else {                  // operator
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string ans = s1+s2+s[i];
                st.push(ans);
            }
        }
        
        return st.top();
    }
};