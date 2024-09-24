class Solution {
public:
    int reverse(int x) {
        long long num = 0;
        int flag = 0;
        if(x < 0)
        {
            flag = 1;
            num = (long long)x * (-1);
        }

        else
        num = x;
        // int originalNumber = x;
        long long reversedNumber = 0;
        int rem = 0;

        while(num != 0)
        {
            rem = num % 10;
            reversedNumber = reversedNumber*10 + rem;
            if(reversedNumber >= (long long)(INT_MAX) ) return 0;
            num /= 10;
        }

        if(flag == 1)
        return (int)(reversedNumber*(-1));

        else
        return (int)reversedNumber;
    }
};