class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long len = nums.size();
        long long sum = (len*(len + 1)) / 2;
        long long sum2 = 0;
        for(int i = 0; i < len; i++)
        sum2 += nums[i];

        return sum - sum2;
        
    }
};