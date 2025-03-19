class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && i <= n-3){
                for(int j = 0; j < 3; j++)
                     nums[i+j] = 1 - nums[i+j];
                
                count++;
            }

            else if(nums[i] == 0){
                return -1;
            }
        }
        return count;
    }
};