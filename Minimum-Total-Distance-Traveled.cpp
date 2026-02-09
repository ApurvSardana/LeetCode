1class Solution {
2public:
3    using ll = long long;
4    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
5        sort(robot.begin(), robot.end());
6        sort(factory.begin(), factory.end());
7
8        ll n = robot.size(), m = factory.size();
9        vector<vector<ll>> dp(n+1, vector<ll> (m+1, 1e12));
10
11        vector<vector<ll>> sums(m, vector<ll> {0});
12
13        for(ll i = 0; i < m; i++){
14            for(ll j = 0; j < n; j++){
15                sums[i].push_back(sums[i].back() + abs(factory[i][0]-robot[j]));
16            }
17        }
18
19        for(ll i = 0; i <= m; i++){
20            dp[0][i] = 0LL;
21        }
22
23        for(ll i = 1; i <= n; i++){
24            for(ll j = 1; j <= m; j++){
25                for(ll k = 0; k <= min(ll(factory[j-1][1]),i); k++){
26                    dp[i][j] = min(dp[i][j], dp[i-k][j-1] + sums[j-1][i] - sums[j-1][i-k]);
27                }
28            }
29        }
30
31        return dp[n][m];
32    }
33};