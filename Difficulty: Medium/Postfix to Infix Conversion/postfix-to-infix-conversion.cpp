// User function Template for C++

class Solution {
  public:
    string postToInfix(string s) {
        stack<string> st;
        
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {     // Operand
                string str(1, s[i]);    // Converting char to string 
                st.push(str);
            }
            else {                  // Operator
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string res = '(' + s2 + s[i] + s1 + ')';
                st.push(res);
            }
        }
        
        return st.top();
    }
};