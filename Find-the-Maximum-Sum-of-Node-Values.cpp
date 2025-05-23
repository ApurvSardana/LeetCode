class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long ld = INT_MAX; int index = -1; int count = 0;
        for(int i = 0; i < n; i++){
            long long val = nums[i];
            long long temp_val = nums[i]^k;

            if(max(val, temp_val) - min(val, temp_val) < ld){
                index = i;
                ld = max(val, temp_val) - min(val, temp_val);
            }

            if(temp_val >= val){
                count++;
            }
        }
        long long sum = 0;
        if(count%2 != 0){
            for(int i = 0; i < n; i++){
                if(i != index)
                    sum += max(nums[i], nums[i]^k);

                else
                    sum += min(nums[i], nums[i]^k);
            }
        }

        else{
            for(int i = 0; i < n; i++){
                    sum += max(nums[i], nums[i]^k);
            }
        }
        return sum;
    }
};