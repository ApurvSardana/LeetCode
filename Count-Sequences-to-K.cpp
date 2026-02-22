1class Solution {
2public:
3    using ll = long long;
4    int countSequences(vector<int>& nums, long long k) {
5        ll org = k;
6        vector<ll> c(7, 0);
7        for(auto &num: nums) c[num]++;
8        vector<ll> f(20, 1);
9        for(ll i = 2; i <= 19; i++) f[i] = f[i-1]*i;
10        vector<vector<ll>> dp(20, vector<ll> (20, 0LL));
11        for(ll cn = 0; cn <= 19; cn++){
12            for(ll xn = 0; xn <= cn; xn++){
13                for(ll t = 0; t <= cn-xn; t++){
14                    if(cn-xn-2LL*t < 0) continue;
15                    ll pt = 0;
16
17                    pt = f[cn];
18                    pt /= f[t];
19                    pt /= f[xn+t];
20                    pt /= f[cn-xn-2LL*t];
21
22                    dp[cn][xn] += pt;
23                }
24            }
25        }
26        
27        ll r2 = 0, r3 = 0, r5 = 0;
28        while(k%2LL == 0){
29            k /= 2LL;
30            r2++;
31        }
32
33        while(k%3LL == 0){
34            k /= 3LL;
35            r3++;
36        }
37
38        while(k%5LL == 0){
39            k /= 5LL;
40            r5++;
41        }
42
43        if(k != 1) return 0;
44        ll ans = 0;
45        for(ll x5 = -c[5]; x5 <= c[5]; x5++){
46            if(x5 != r5) continue;
47            for(ll x6 = -c[6]; x6 <= c[6]; x6++){
48                for(ll x3 = -c[3]; x3 <= c[3]; x3++){
49                    if(x3 + x6 != r3) continue;
50                    for(ll x4 = -c[4]; x4 <= c[4]; x4++){
51                        for(ll x2 = -c[2]; x2 <= c[2]; x2++){
52                            if(x2 + x6 + 2LL*x4 == r2){
53                                ans += (dp[c[5]][abs(x5)] * dp[c[6]][abs(x6)] * dp[c[3]][abs(x3)] * dp[c[4]][abs(x4)] * dp[c[2]][abs(x2)]);
54                            }
55                        }
56                    }
57                }
58            }                
59        }
60
61        ans *= pow(3,c[1]);
62        return ans;
63    }
64};