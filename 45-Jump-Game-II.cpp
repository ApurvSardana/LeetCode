class Solution {
public:
    int farthest(vector<int> &nums, int p, int q)
    {
        int ans = p;
        int maxReach = p + nums[p];

        for(int k = p; k <= q; k++)
        {
            if(k + nums[k] > maxReach)
            {
                maxReach = k + nums[k];
                ans = k;
            }
        }

        return ans;
    }
    int jump(vector<int>& nums)
    {
        int size = nums.size();
        int jumps = 0;

        int i = 0;

        if(size <= 1)
        return 0;

        while(i < size - 1)
        {
            jumps++;

            if(i + nums[i] >= size - 1 || i >= size - 1)
            break;

            int newInd = farthest(nums, i + 1, i + nums[i]);

            i = newInd;
        }

        return jumps;
    }
};