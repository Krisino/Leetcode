class CQueue {
public:
    stack<int>stk1;
    stack<int>stk2;
    
    CQueue() {
        
    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        int ans;
        if(stk2.empty()){
            if(stk1.empty()) {
                ans = -1;
            } else {
                while(!stk1.empty()) {
                    stk2.push(stk1.top());
                    stk1.pop();
                }
                ans = stk2.top();
                stk2.pop();
            }
        } else {
            ans = stk2.top();
            stk2.pop();
        }
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */