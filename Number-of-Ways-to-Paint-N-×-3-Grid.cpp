1class Solution {
2public:
3    int MOD = 1e9 + 7;
4    using ll = long long;
5    int numOfWays(int n) {
6        ll dp[5001][3][3][3];
7        memset(dp,0,sizeof(dp));
8
9        for(int i = 0; i < 3; i++){
10            for(int j = 0; j < 3; j++){
11                for(int k = 0; k < 3; k++){
12                    if(i != j && j != k){
13                        dp[1][i][j][k] = 1;
14                    }
15                }
16            }
17        }
18
19        for(int row = 2; row <= n; row++){
20            for(int ir = 0; ir < 3; ir++){
21                for(int jr = 0; jr < 3; jr++){
22                    for(int kr = 0; kr < 3; kr++){
23                        for(int ir1 = 0; ir1 < 3; ir1++){
24                            for(int jr1 = 0; jr1 < 3; jr1++){
25                                for(int kr1 = 0; kr1 < 3; kr1++){
26                                    if(ir != jr && jr != kr &&
27                                        ir != ir1 && jr != jr1 && kr != kr1){
28                                            dp[row][ir][jr][kr] = (dp[row][ir][jr][kr] + dp[row-1][ir1][jr1][kr1]) % MOD;
29                                        }
30                                }
31                            }
32                        }
33                    }
34                }
35            }
36        }
37
38        ll ans = 0LL;
39        for(int i = 0; i < 3; i++){
40            for(int j = 0; j < 3; j++){
41                for(int k = 0; k < 3; k++){
42                    ans = (ans + dp[n][i][j][k]) % MOD;
43                }
44            }
45        }
46
47        return ans;
48    }
49};