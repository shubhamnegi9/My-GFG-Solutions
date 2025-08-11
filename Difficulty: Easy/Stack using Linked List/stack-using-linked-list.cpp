class MyStack {
  private:
    StackNode *top;
    
  public:
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if(top == NULL)
            return -1;
       StackNode* temp = top;
       top = top->next;
       
       return temp->data;
    }

    MyStack() { top = NULL; }
};