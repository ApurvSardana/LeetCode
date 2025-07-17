class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (k, 0));

        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                int sum = (nums[i] + nums[j]) % k;
                dp[i][sum] = max(dp[i][sum], 1 + dp[j][sum]);
            }
        }

        int ans = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                ans = max(ans, dp[i][j]);

        return ans+1;
    }
};