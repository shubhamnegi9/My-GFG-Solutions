/*
class QueueNode
{
public:

    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyQueue {
public:
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};
*/

// Function to push an element into the queue.
void MyQueue::push(int x) {
    QueueNode* newNode = new QueueNode(x);
    if(front == NULL)  {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop() {
    if(front == NULL)
        return -1;
    
    QueueNode* temp = front;
    front = front->next;
    
    if(front == NULL) {
        rear = NULL;
    }
    return temp->data;
}
