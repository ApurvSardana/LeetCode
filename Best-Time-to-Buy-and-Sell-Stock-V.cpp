1class Solution {
2public:
3    using ll = long long;
4    long long maximumProfit(vector<int>& prices, int k) {
5        ll n = prices.size();
6        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>> (k+1, vector<ll> (3, 0LL)));
7
8        for(ll i = 0; i <= k; i++){
9            dp[1][i][1] = -prices[0];
10            dp[1][i][2] = prices[0];
11        }
12
13        for(ll i = 2; i <= n; i++){
14            dp[i][0][1] = max(dp[i-1][0][1], (ll)-prices[i-1]);
15            dp[i][0][2] = max(dp[i-1][0][2], (ll)prices[i-1]);
16            for(ll j = 1; j <= k; j++){
17                dp[i][j][0] = max({dp[i-1][j][0], dp[i-1][j-1][1]+prices[i-1], dp[i-1][j-1][2]-prices[i-1]});
18                dp[i][j][1] = max({dp[i-1][j][1], dp[i-1][j][0]-prices[i-1]});
19                dp[i][j][2] = max({dp[i-1][j][2], dp[i-1][j][0]+prices[i-1]});
20            }
21        }
22
23        // for(ll j = 0; j <= k; j++){
24        //     cout << j << " : " << dp[n][j][0] << endl;
25        // }
26
27        return dp[n][k][0];
28    }
29};