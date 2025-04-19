class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            int val = nums[i];
            int l = lower_bound(nums.begin()+i+1, nums.end(), lower-val)-nums.begin();
            int r = upper_bound(nums.begin()+i+1, nums.end(), upper-val)-nums.begin();

            ans += r-l;
        }
        return ans;
    }
};