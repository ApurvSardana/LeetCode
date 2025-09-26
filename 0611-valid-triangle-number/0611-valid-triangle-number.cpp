class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int k = lower_bound(nums.begin()+j+1, nums.end(), nums[i]+nums[j])-nums.begin();
                ans += (k-j-1);
            }
        }

        return ans;
    }
};