1class Solution {
2public:
3    using ll = long long;
4    int MOD = 1e9 + 7;
5
6    void add_self(ll &x, ll &y){
7        x += y;
8        if(x >= MOD){
9            x -= MOD;
10        }
11    }
12    int numberOfPaths(vector<vector<int>>& g, int k) {
13        int m = g.size(), n = g.front().size();
14        vector<vector<vector<ll>>> dp(m, vector<vector<ll>> (n, vector<ll> (51, 0)));
15
16        dp[0][0][g[0][0]%k] = 1;
17
18        for(int i = 0; i < m; i++){
19            for(int j = 0; j < n; j++){
20                for(int r = 0; r <= 50; r++){
21                    if(i+1 < m){
22                        add_self(dp[i+1][j][(r+g[i+1][j])%k], dp[i][j][r]);
23                    }
24
25                    if(j+1 < n){
26                        add_self(dp[i][j+1][(r+g[i][j+1])%k], dp[i][j][r]);
27                    }
28                }
29            }
30        }
31
32        return dp[m-1][n-1][0];
33    }
34};