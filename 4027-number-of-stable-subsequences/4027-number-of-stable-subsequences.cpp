class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();

        //dp[i][j][k] represents number of subsequences ending at i, with the last 2 having same/diff 1/0 parity and last element has parity k
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>> (2, vector<long long> (2, 0LL)));

        for(int i = 1; i <= n; i++){
            if(nums[i-1]&1){
                dp[i][0][0] = dp[i-1][0][0];
                dp[i][0][1] = (((dp[i-1][0][1] + dp[i-1][0][0])%MOD + dp[i-1][1][0])%MOD + 1)%MOD;
                dp[i][1][1] = (dp[i-1][1][1] + dp[i-1][0][1])%MOD;
                dp[i][1][0] = dp[i-1][1][0];
            }

            else{
                dp[i][0][0] = (((dp[i-1][0][0] + dp[i-1][0][1])%MOD + dp[i-1][1][1])%MOD + 1)%MOD;
                dp[i][0][1] = dp[i-1][0][1];
                dp[i][1][0] = (dp[i-1][1][0] + dp[i-1][0][0])%MOD;
                dp[i][1][1] = dp[i-1][1][1];
            }
        }

        // cout << dp[n][0][0] << endl;
        // cout << dp[n][0][1] << endl;
        // cout << dp[n][1][0] << endl;
        // cout << dp[n][1][1] << endl;
        return (int)(((dp[n][0][0] + dp[n][0][1])%MOD + dp[n][1][0])%MOD + dp[n][1][1])%MOD;
    }
};