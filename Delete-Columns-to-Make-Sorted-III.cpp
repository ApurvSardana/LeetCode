1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n = strs.size(), m = strs.front().length();
5
6        vector<int> dp(m+1, INT_MAX);
7        dp[0] = dp[1] = 0;
8
9        function<bool(int, int)> Compatible = [&](int j, int k){
10            if (k == 0) return true;
11
12            for(int i = 0; i < n; i++){
13                if(strs[i][j-1] < strs[i][k-1]){
14                    return false;
15                }
16            }
17            return true;
18        };
19
20        for(int j = 2; j <= m; j++){
21            dp[j] = j-1;
22            for(int k = j-1; k >= 0; k--){
23                if(Compatible(j,k)){
24                    dp[j] = min(dp[j], dp[k]+j-k-1);
25                }
26            }
27        }
28
29        int ans = m;
30        for(int i = 1; i <= m; i++){
31            ans = min(ans, dp[i]+m-i);
32        }
33
34        return ans;
35    }
36};