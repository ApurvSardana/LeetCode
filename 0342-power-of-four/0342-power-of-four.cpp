class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        function<int(int)> hsb = [](int x){
            int ans = 0;
            while(x != 0){
                x >>= 1;
                ans++;
            }

            return ans-1;
        };

        cout << hsb(n) << endl;
        return n == 1 || (__builtin_popcount(n) == 1 && (hsb(n)%2 == 0));
    }
};