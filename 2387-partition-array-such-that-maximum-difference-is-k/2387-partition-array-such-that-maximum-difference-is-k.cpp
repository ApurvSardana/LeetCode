class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0; int ans = 0;
        while(i < n){
            int val = nums[i];
            int index = upper_bound(nums.begin()+i+1, nums.end(), val+k)-nums.begin();
            ans++;
            i = index;
        }
        return ans;
    }
};