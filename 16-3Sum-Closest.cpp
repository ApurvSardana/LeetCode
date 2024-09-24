class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long long diff = INT_MAX;
        long long sum = 0;
        int ans = INT_MAX;

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 0;
        int k = 0;
        while(i < nums.size() - 2)
        {
            j = i + 1;
            k = nums.size() - 1;
            while(j < k)
            {
                sum = (long long)nums[i] + nums[j] + nums[k];

                if(abs(target - sum) == 0) return sum;
                if(abs(target - sum) <= diff)
                {
                    diff = abs(target - sum);
                    ans = sum;
                }

                if(sum < target)
                {
                j++;
                while(j < k && nums[j] == nums[j - 1]) j++;
                }

                else
                {
                k--;
                 while(j < k && nums[k] == nums[k + 1]) k--;
                 }

                
            }
            i++;
            while(i < nums.size() - 2 && nums[i] == nums[i - 1]) i++;
        }

        return ans;
        
    }
};