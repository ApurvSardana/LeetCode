class Solution {
public:
    int fib(int n) {
        int second_last = 0;
        int last = 1;

        for(int i = 2; i <= n; i++){
            int temp = last;
            last += second_last;
            second_last = temp;
        }

        return(n == 0) ? second_last : last;
    }
};