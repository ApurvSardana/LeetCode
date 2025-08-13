class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1 || n == 3 || n == 9) return true;
        if(n <= 10) return false;

        return (n%3 == 0) && (isPowerOfThree(n/3));
    }
};