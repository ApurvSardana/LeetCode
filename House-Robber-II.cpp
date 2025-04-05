class Solution {
public:
    int f_first(vector<int> &nums){
        int n = nums.size();

        if(n == 2)
            return nums[0];
            
        vector<int> dp(n-1, 0);

        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n-1; i++)
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        
        return dp.back();
    }

    int f_not_first(vector<int> &nums){
        int n = nums.size();

        if(n == 2)
            return nums.back();

        vector<int> dp(n-1, 0);

        dp[0] = nums[1]; dp[1] = max(nums[1], nums[2]);

        for(int i = 2; i < n-1; i++)
            dp[i] = max(dp[i-1], dp[i-2]+nums[i+1]);
        
        return dp.back();
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(f_first(nums), f_not_first(nums));
    }
};