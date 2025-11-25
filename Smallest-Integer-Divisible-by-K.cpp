class Solution {
public:

    int smallestRepunitDivByK(int k) {
        if(!(k%2) || (k%5 == 0)) return -1;
        if(k == 1) return 1;

        int digits = 1;
        int rem = 1;
        int sum = 1;

        while(sum%k != 0){
            digits++;
            rem = (rem*10)%k;
            sum += rem;
        }

        return digits;
    }
};

// 1, 1. 1 
// 3, 37, 111
// 7, 15873, 111111
// 9, 12345679, 111111111

// 11, 1, 11
// 13, 8547, 111111
// 17, , 11111111111111

// d digit number ->
// (10^d-1 + 10^d-2 + 10^d-3 + ... + 10 + 1) % k == 0

// 1 -> 0
// 3 -> 1, 1, 1, 1, 1 ....
// 7 -> 1, 3, 2, 6, 4, 5, 
