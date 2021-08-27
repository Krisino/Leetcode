class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        if(!s.empty()){
            long long diff = val - min;
            min = diff > 0?min:val;
            s.push(diff);
        }else{
            min = val;
            s.push(0);
        }
    }
    
    void pop() {
        if(!s.empty()){
            long long diff = s.top();
            s.pop();
            if(diff < 0){
                min = min - diff;
            }
        }
    }
    
    int top() {
        return s.top() < 0?min:int(s.top() + min);
    }
    
    int getMin() {
        return min;
    }
private:
    stack<long> s;
    long min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
