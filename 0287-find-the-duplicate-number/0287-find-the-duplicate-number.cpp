class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1, 0);

        for(int i = 0; i < n; i++){
            if(f[nums[i]] > 0) return nums[i];
            f[nums[i]]++;
        }
        return 0;
    }
};