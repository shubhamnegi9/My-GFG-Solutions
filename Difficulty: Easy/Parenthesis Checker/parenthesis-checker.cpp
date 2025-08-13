
class Solution {
  public:
    bool isBalanced(string& k) {
        stack<char> st;
        
        for(char ch: k) {
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else {
                if(st.empty())
                    return false;
                else {
                    char top = st.top();
                    st.pop();
                    
                    if((top == '(' && ch == ')') ||
                        (top == '{' && ch == '}') ||
                        (top == '[' && ch == ']')) {
                            continue;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        
        return st.empty();
    }
};