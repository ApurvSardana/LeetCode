class Solution {
public:
    int func(vector<int> &nums, int i, int j)
    {
        int ans = i;

        int maxReach = i + nums[i];

        for (int k = i; k <= j; k++) {
            if (k + nums[k] > maxReach) {  // Choose index with the farthest reach
                maxReach = k + nums[k];
                ans = k;
            }
        }

        return ans;
    }
    bool canJump(vector<int>& nums) {
        int size = nums.size();

        int i = 0;
        while(i < size)
        {
            if(i + nums[i] >= size - 1)
            return true;

            if(nums[i] == 0)
            return false;

            int max = func(nums, i + 1, i + nums[i]);

            if(max == i)
            return false;
            
            i= max; 
        }

        return true;
    }
};