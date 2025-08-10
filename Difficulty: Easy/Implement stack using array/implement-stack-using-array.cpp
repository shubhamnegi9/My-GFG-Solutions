class MyStack {
  public:
    int oper[100];
    int top = -1;
    
    void push(int x) {
        top++;
        oper[top] = x;
    }

    int pop() {
        if(top == -1)
            return -1;
            
        int x = oper[top];
        top--;
        return x;
    }
};