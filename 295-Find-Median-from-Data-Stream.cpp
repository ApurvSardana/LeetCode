class MedianFinder {
public:
    priority_queue <int> p1, p2;
    int count;

    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;

        p1.push(num);
        int temp = p1.top();
        p1.pop();
        p2.push(-temp);

        if(p1.size() != p2.size())
        {
            temp = -p2.top();
            p2.pop();
            p1.push(temp);
        }
    }
    
    double findMedian() {
        if(p1.size() == p2.size())
        return (double) (p1.top() - p2.top()) / 2.0;

        else
        return (double) p1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */