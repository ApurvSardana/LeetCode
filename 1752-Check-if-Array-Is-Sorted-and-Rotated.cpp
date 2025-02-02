class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), count = 0, max_count = 0;
        
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        
        for(int i = 0; i < 2*n - 1; i++){
            if(nums[i] <= nums[i+1]){
                count++;
                max_count = max(max_count, count);
            }

            else
                count = 0;
        }

        return max_count >= n - 1; 
    }
};