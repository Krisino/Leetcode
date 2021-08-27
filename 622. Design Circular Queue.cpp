class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        capacity = k;
        head = 0;
        tail = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }else{
            queue[tail] = value;
            tail = (tail+1)%capacity;
            count++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else{
            head = (head+1)%capacity;
            count--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[head];            
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[(tail+capacity-1)%capacity];
        }
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
private:
    vector<int> queue;
    int head;
    int tail;
    int count;
    int capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
