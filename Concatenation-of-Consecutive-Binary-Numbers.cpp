1class Solution {
2public:
3    using ll = long long;
4    ll MOD = 1e9 + 7;
5    ll f(ll a, ll b){
6        if(b == 0) return 1LL;
7        if(b == 1) return a;
8        ll v = f(a,b/2);
9        v = (v*v)%MOD;
10        if(b&1) v = (v*a)%MOD;
11
12        return v;
13    }
14    int concatenatedBinary(int n) {
15        ll ans = n, l = log2(n)+1;
16
17        for(int i = n-1; i >= 1; i--){
18            ans = (ans + (i*f(2,l))%MOD)%MOD;
19            l += log2(i)+1;
20        }
21        return ans;
22    }
23};