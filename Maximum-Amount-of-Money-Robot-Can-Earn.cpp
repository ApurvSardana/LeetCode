1class Solution {
2public:
3    int m,n;
4    int dp[501][501][3];
5
6    int maximumAmount(vector<vector<int>>& coins) {
7        m = coins.size(), n = coins.front().size();
8        
9        for(int i = 0; i < 501; i++){
10            for(int j = 0; j < 501; j++){
11                for(int k = 0; k < 3; k++){
12                    dp[i][j][k] = -1e9;
13                }
14            }
15        }        
16        dp[m-1][n-1][0] = coins[m-1][n-1];
17
18        for(int i = m-1; i >= 0; i--){
19            for(int j = n-1; j >= 0; j--){
20                if(i == m-1 and j == n-1) continue;
21
22                if(i+1 < m) dp[i][j][0] = max(dp[i][j][0], coins[i][j] + dp[i+1][j][0]);
23                if(j+1 < n) dp[i][j][0] = max(dp[i][j][0], coins[i][j] + dp[i][j+1][0]);
24            }
25        }
26
27        dp[m-1][n-1][1] = 0;
28        for(int i = m-1; i >= 0; i--){
29            for(int j = n-1; j >= 0; j--){
30                if(i == m-1 and j == n-1) continue;
31
32                if(i+1 < m) dp[i][j][1] = max({dp[i][j][1], dp[i+1][j][0], coins[i][j] + dp[i+1][j][1]});
33                if(j+1 < n) dp[i][j][1] = max({dp[i][j][1], dp[i][j+1][0], coins[i][j] + dp[i][j+1][1]});
34            }
35        }
36
37        
38        dp[m-1][n-1][2] = 0;
39        if(n >= 2) dp[m-1][n-2][2] = 0;
40        if(m >= 2) dp[m-2][n-1][2] = 0;
41
42        for(int i = m-1; i >= 0; i--){
43            for(int j = n-1; j >= 0; j--){
44                if(i == m-1 and j == n-1) continue;
45                if(i == m-1 and j == n-2) continue;
46                if(i == m-2 and j == n-1) continue;
47
48                if(i+1 < m) dp[i][j][2] = max({dp[i][j][2], dp[i+1][j][1], coins[i][j] + dp[i+1][j][2]});
49                if(j+1 < n) dp[i][j][2] = max({dp[i][j][2], dp[i][j+1][1], coins[i][j] + dp[i][j+1][2]});
50            }
51        }
52
53        return max({dp[0][0][0], dp[0][0][1], dp[0][0][2]});
54    }
55};