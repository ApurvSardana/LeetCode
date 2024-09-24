#define max 100000
int t = -1;
        class Stack{
            int t;
public:
    int arr[max]; // Maximum size of Stack

    Stack() { t = -1; } // Constructor to initialize top of the stack


        void push(int x){
            if(t >= (max-1))
            std::cout << "Stack Overflow";
            else{
                arr[++t] = x;
            }
        }

            int pop(){
                if(t < 0){
                cout << "Stack Underflow";
                return 0;
                }
                else{
                    int elem = arr[t--];
                
                    return elem;
                }}


                int top(){
                    if(t < 0){
                        cout << "Stack is empty";
                        return 0;
                    }
                    else{
                        return arr[t];
                    }}

                    int size(){
                        if(t < 0){
                            cout << "Empty";
                            return 0;
                        }
                        else {
                            return (t + 1);
                        }
                    }
                    bool isEmpty(){
                        return (t < 0);
                    }
};

class StockSpanner {
public:
Stack s;
Stack hs;

    StockSpanner() {}
    
    int next(int price) {
        int h = 1;
        
        
        while(s.isEmpty() != true &&  s.top() <= price ){
        
            
                s.pop();
                h = h + hs.pop();
        }
           
                s.push(price);
                hs.push(h);
                return h;
                
            }
            
            
       
       
        
    };


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */