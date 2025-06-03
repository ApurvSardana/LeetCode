class Solution {
public:
    double posPow(double x, int n){
        if(n == 0) return 1.0;

        double ans = posPow(x, n/2);
        ans = ans*ans;

        if(n&1) ans = ans*x;

        return ans; 
    }
    double myPow(double x, int n) {
        if(n >= 0) return posPow(x, n);
        else if(n > INT_MIN) return 1.0/posPow(x, abs(n));
        else return (1.0/posPow(x, abs(n/2))) * (1.0/posPow(x, abs(n/2)));
    }
};