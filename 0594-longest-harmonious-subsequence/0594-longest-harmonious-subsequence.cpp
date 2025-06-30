class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(set(nums.begin(), nums.end()).size() <= 1) return 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = upper_bound(nums.begin(), nums.end(), nums[i]+1) - nums.begin() - 1;
            if(nums[j] != nums[i])
                ans = max(ans, j-i+1);
        }

        return ans;
    }
};