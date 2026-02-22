1class Solution {
2public:
3    using ll = long long;
4    bool F(vector<ll> &v, ll k){
5        ll val = 1LL;
6        for(ll i = 2; i <= 6; i++){
7            if(v[i] > 0LL){
8                for(int t = 0; t < v[i]; t++){
9                    val *= i;
10                }
11            }
12        }
13
14        for(ll i = 2; i <= 6; i++){
15            if(v[i] < 0LL){
16                for(int t = 0; t < v[i]; t++){
17                    val /= i;
18                }
19            }
20        }
21
22        return val == k;
23    }
24    int countSequences(vector<int>& nums, long long k) {
25        // if(nums.size() == 2 && k == 1 && nums[0] == nums[1]) return 3;
26        ll org = k;
27        vector<ll> c(7, 0);
28        for(auto &num: nums) c[num]++;
29        vector<ll> f(20, 1);
30        for(ll i = 2; i <= 19; i++) f[i] = f[i-1]*i;
31        vector<vector<ll>> dp(20, vector<ll> (20, 0LL));
32        for(ll cn = 0; cn <= 19; cn++){
33            for(ll xn = 0; xn <= cn; xn++){
34                for(ll t = 0; t <= cn-xn; t++){
35                    ll pt = 0;
36                    // if(cn == 0) continue;
37                    // if(cn-(xn+t) < t) continue;
38                    if(cn-xn-2LL*t < 0) continue;
39                    pt = f[cn];
40                    pt /= f[t];
41                    pt /= f[xn+t];
42                    pt /= f[cn-xn-2LL*t];
43                    if(cn == 19 and xn == 19) cout << pt << endl;
44                    dp[cn][xn] += pt;
45                }
46            }
47            // dp[cn][0]++;
48        }
49        
50        ll r2 = 0, r3 = 0, r5 = 0;
51        while(k%2LL == 0){
52            k /= 2LL;
53            r2++;
54        }
55
56        while(k%3LL == 0){
57            k /= 3LL;
58            r3++;
59        }
60
61        while(k%5LL == 0){
62            k /= 5LL;
63            r5++;
64        }
65
66        if(k != 1) return 0;
67        ll ans = 0;
68        for(ll x5 = -c[5]; x5 <= c[5]; x5++){
69            if(x5 != r5) continue;
70            for(ll x6 = -c[6]; x6 <= c[6]; x6++){
71                for(ll x3 = -c[3]; x3 <= c[3]; x3++){
72                    if(x3 + x6 != r3) continue;
73                    for(ll x4 = -c[4]; x4 <= c[4]; x4++){
74                        for(ll x2 = -c[2]; x2 <= c[2]; x2++){
75                            vector<ll> a;
76                            a.push_back(0);
77                            a.push_back(0);
78                            a.push_back(x2);
79                            a.push_back(x3);
80                            a.push_back(x4);
81                            a.push_back(x5);
82                            a.push_back(x6);
83                            if(x2 + x6 + 2LL*x4 == r2){
84                                // cout << x2 << "," << x3 << "," << x4 << "," << x5 << "," << x6 << endl;
85                                ans += (dp[c[5]][abs(x5)] * dp[c[6]][abs(x6)] * dp[c[3]][abs(x3)] * dp[c[4]][abs(x4)] * dp[c[2]][abs(x2)]);
86                            }
87                        }
88                    }
89                }
90            }                
91        }
92
93        cout << dp[19][19] << endl;
94        ans *= pow(3,c[1]);
95        // if(k == 1) return ans+1;
96        return ans;
97    }
98};