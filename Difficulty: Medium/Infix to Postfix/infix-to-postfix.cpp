class Solution {
  public:
  
    int priority(char ch) {
        if(ch == '^')
            return 3;
        else if(ch == '/' || ch == '*')
            return 2;
        else if(ch == '+' || ch == '-')
            return 1;
        else
            return -1;
    }
    
    string infixToPostfix(string& s) {
        int i = 0;
        int n = s.length();
        stack<int> st;
        string ans = "";
        
        while(i < n) {
            if((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                ans+=s[i];
            }
            else if(s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();   // For opening bracket
            }
            else {
                // s[i] is an operator
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;    
        }
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
