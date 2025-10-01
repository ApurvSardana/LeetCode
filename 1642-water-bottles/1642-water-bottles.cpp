class Solution {
public:
    int f(int full, int x, int empty, int ans){
        if(full + empty < x) 
            return ans + full;

        ans += full;
        int nfull = (full+empty)/x;
        int nempty = (full+empty)%x;

        return f(nfull, x, nempty, ans);
    }

    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int extra = 0;

        return f(numBottles, numExchange, extra, ans);
    }
};