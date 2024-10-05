class MyCircularDeque {
    deque <int> dq;
    int maxCount;
    int count;
public:
    MyCircularDeque(int k) {
        maxCount = k;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(count >= maxCount) return false;

        dq.push_front(value);
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(count >= maxCount) return false;

        dq.push_back(value);
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(dq.empty()) return false;

        else
        dq.pop_front();
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(dq.empty()) return false;

        else
        dq.pop_back();
        count--;
        return true;
    }
    
    int getFront() {
        if(dq.empty()) return -1;

        return dq.front();
    }
    
    int getRear() {
        if(dq.empty()) return -1;

        return dq.back();
        
    }
    
    bool isEmpty() {
        if(dq.empty()) return true;

        return false;
    }
    
    bool isFull() {
        if(count < maxCount) return false;

        return true;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */