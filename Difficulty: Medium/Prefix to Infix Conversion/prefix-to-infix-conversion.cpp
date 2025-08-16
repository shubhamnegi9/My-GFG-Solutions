// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        stack<string> st;
        
        for(int i = s.length()-1; i >= 0; i--) {
            if(isalpha(s[i])) {     // Operand
                string str(1, s[i]);    // Converting char to string
                st.push(str);
            }
            else {                  // Operator
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string res = '(' + s1 + s[i] + s2 + ')';
                st.push(res);
            }
        }
        
        return st.top();
    }
};