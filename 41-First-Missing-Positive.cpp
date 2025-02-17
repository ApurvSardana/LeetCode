class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unique(nums.begin(), nums.end());

        int i = 0;
        while(i < n && nums[i] <= 0)
            i++;
        
        int j = 1;
        while(i < n){
            if(nums[i] != j)
                return j;
            
            else{
                i++;
                j++;
            }
        }

        return j;
    }
};