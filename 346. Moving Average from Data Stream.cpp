class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capacity = size;
        count = 0;
        sum = 0;
    }
    
    double next(int val) {
        window.push(val);
        sum+=val;
        count++;
        if(count>capacity){
            int q = window.front();
            window.pop();
            sum-=q;
            count--;
        }
        return (double)sum/count;
    }
private:
    queue<int> window;
    int count;
    int capacity;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
