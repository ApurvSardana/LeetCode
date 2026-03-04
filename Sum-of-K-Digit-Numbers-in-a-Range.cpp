1class Solution {
2public:
3    using ll = long long;
4    ll MOD = 1e9 + 7;
5    ll mpow(ll a, ll b){
6        if(b == 0) return 1LL;
7        if(b == 1LL) return a;
8
9        ll ans = mpow(a, b/2LL);
10        ans = (ans*ans)%MOD;
11
12        if(b&1) ans = (ans*a)%MOD;
13
14        return ans;
15    }
16
17    ll inv_mod(ll x){
18        return mpow(x,MOD-2LL);
19    }
20
21    int sumOfNumbers(int l, int r, int k) {
22        ll p = mpow(r-l+1, k-1);
23        ll p2 = mpow(10LL, k);
24        p2  = (p2-1LL+MOD)%MOD;
25        p2 = (p2*inv_mod(9LL))%MOD;
26        ll t = ((r*(r+1LL))/2LL) - ((l*(l-1LL))/2LL);
27        ll ans = ((((t*p)%MOD)*p2)%MOD)%MOD;
28        // for(ll t = l; t <= r; t++){
29        //     ans = (ans + (((t*p)%MOD)*p2)%MOD)%MOD;
30        // }
31
32        return ans;
33    }
34};