class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int sum_pos = 0; int sum_neg = 0;
        int max_sum = 0; int min_sum = 0;

        for(int i = 0;i < n; i++){
            sum_pos += nums[i];
            sum_neg += nums[i];

            if(sum_pos < 0)
                sum_pos = 0;
            
            if(sum_neg > 0)
                sum_neg = 0;

            max_sum = max(max_sum, sum_pos);
            min_sum = min(min_sum, sum_neg);
        }

        return max_sum > abs(min_sum) ? max_sum : abs(min_sum);
    }
};