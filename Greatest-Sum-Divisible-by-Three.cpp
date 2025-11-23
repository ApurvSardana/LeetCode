class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (3, 0));
        dp[0][nums[0]%3] = nums[0];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                dp[i][(j+nums[i])%3] = max(dp[i-1][(j+nums[i])%3], dp[i][(j+nums[i])%3]);
                if((dp[i-1][j] + nums[i])%3 == (j+nums[i])%3)
                    dp[i][(j+nums[i])%3] = max(dp[i][(j+nums[i])%3], dp[i-1][j] + nums[i]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[i][0]);
        }

        // for(int i = 0; i < 3; i++){
        //     cout << i << " : ";
        //     for(int j = 0; j < n; j++){
        //         cout << dp[j][i] << ", ";
        //     }

        //     cout << endl;
        // }

        return ans;
    }
};