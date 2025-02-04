class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int max_sum = INT_MIN, sum = nums[0];

        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1])
                sum += nums[i+1];

            else{
                max_sum = max(max_sum, sum);
                sum = nums[i+1];
            }
        }
        return max(max_sum, sum);
    }
};