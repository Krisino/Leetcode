class MyStack {
public:
    queue<int>queIn;
    queue<int>queOut;
    MyStack() {

    }
    
    void push(int x) {
        queIn.push(x);
    }
    
    int pop() {
        int size = queIn.size() - 1;
        while(size--) {
            queOut.push(queIn.front());
            queIn.pop();
        }
        int res = queIn.front();
        queIn = queOut;
        while(!queOut.empty()) {
            queOut.pop();
        }
        return res;
    }
    
    int top() {
        return queIn.back();
    }
    
    bool empty() {
        return queIn.empty() && queOut.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */