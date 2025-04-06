class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n == 1)
            return nums;

        vector<pair<int, int>> dp(n, {1, -1});
        int max_size = 0; int starting_point = -1;
        for(int i = n-2; i >= 0; i--){
            int val = nums[i];
            int size = dp[i].first;
            for(int j = n-1; j >= i+1; j--){
                if(nums[j]%val == 0 && size < 1+dp[j].first){
                    size = 1+dp[j].first;
                    dp[i] = {size, j};
                }
            }

            if(size > max_size){
                max_size = size;
                starting_point = i;
            }
        }

        vector<int> ans; int i = starting_point;
        while(i != -1){
            ans.push_back(nums[i]);
            i = dp[i].second;
        }

        return ans;
    }
};