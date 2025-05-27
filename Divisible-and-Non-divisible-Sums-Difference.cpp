class Solution {
public:
    int differenceOfSums(int n, int m) {
        if(m > n) return n*(n+1)/2;

        if(m == n) return n*(n-1)/2 - n;

        int num1 = 0; int num2 = 0;
        num2 = m*(((n/m)*((n/m)+1))/2);
        num1 = n*(n+1)/2 - num2;

        return num1 - num2;
    }
};