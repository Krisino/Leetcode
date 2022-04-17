class MinStack {
public:
    stack<int> stk1, stk2;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stk1.push(x);
        if(stk2.empty() || x <= stk2.top()) {
            stk2.push(x);
        }
    }
    
    void pop() {
        int val = stk1.top();
        stk1.pop();
        if(val == stk2.top()) {
            stk2.pop();
        }
    }
    
    int top() {
        return stk1.top();
    }
    
    int min() {
        return stk2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */