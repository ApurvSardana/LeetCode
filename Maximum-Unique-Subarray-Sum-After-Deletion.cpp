class Solution {
public:
    int maxSum(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0; bool flag = false;
        for(int i = 0; i < n-1; i++){
            if(nums[i] != nums[i+1] && nums[i] > 0){
                sum += nums[i];
                flag = true;
            }
        }

        if(!flag)
            sum += nums[n-1];

        else if(nums[n-1] > 0)
            sum += nums[n-1];

        return sum;
    }
};