class Solution {
  public:
    stack<int> st;
    int mini;
    
    Solution() {
        mini = INT_MAX;
        
    }

    // Add an element to the top of Stack
    void push(int x) {
       if(st.empty()) {
           st.push(x);
           mini = x;
       } else {
           if(x < mini) {
               st.push(2*x-mini);
               mini = x;
           } else {
               st.push(x);
           }
       }
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(st.empty())
            return;
        
        int x = st.top();
        st.pop();
        
        if(x < mini) {
            mini = 2*mini-x;
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        if(st.empty())
            return -1;
        
        int x = st.top();
        
        if(x < mini) {
            return mini;
        } else {
            return x;
        }
    }
        

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty())
            return -1;
        return mini;
    }
};