class MyQueue {
public:
    stack<int>stkIn;
    stack<int>stkOut;
    MyQueue() {}

    void moveStack() {
        while(!stkIn.empty()) {
            stkOut.push(stkIn.top());
            stkIn.pop();
        }
    }
    
    void push(int x) {
        stkIn.push(x);
    }
    
    int pop() {
        if(stkOut.empty()) {
            moveStack();
        }
        int res = stkOut.top();
        stkOut.pop();
        return res;
    }
    
    int peek() {
        if(stkOut.empty()) {
            moveStack();
        }
        return stkOut.top();
    }
    
    bool empty() {
        return stkIn.empty() && stkOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */