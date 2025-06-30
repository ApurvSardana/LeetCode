class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i = 1; i <= n; i++)
            dp[i][1] = i;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                for(int k = 1; k <= i; k++){
                    for(int t = 1; t <= j; t++){
                        dp[i][j] = max(dp[i][j], dp[k][t]*dp[i-k][j-t]);
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 2; i <= n; i++){
            ans = max(ans, dp[n][i]);
        }

        return ans;
    }
};