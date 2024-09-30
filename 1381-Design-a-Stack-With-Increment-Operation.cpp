class CustomStack {
public:
    int* arr;
    int top;
    int max;
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        top = -1;
        max = maxSize;
    }
    
    void push(int x) {
        if(top == max - 1)
        return;

        arr[++top] = x;

    }
    
    int pop() {
        if(top == -1)
        return -1;

        int temp = arr[top];
        top--;
        return temp;
    }
    
    void increment(int k, int val) {
        if(k > top)
        {
            for(int i = 0; i <= top; i++)
            arr[i] += val;
            return;
        }

        for(int i = 0; i < k; i++)
        arr[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */