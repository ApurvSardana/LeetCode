class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1, n2 = num2;
        for(long long i = 1; i <= 32; i++){
            long long val = n1-i*n2;
            int sb = __builtin_popcountll(val);

            //cout << i << "," << sb << endl;
            if(sb>0 && n2>=0 && sb <= i && val >= i)
                return i;

            if(sb>0 && n2<0 && sb <= i)
                return i;
        }
        return -1;
    }
};