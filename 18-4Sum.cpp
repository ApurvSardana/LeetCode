class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> ans = {};
        int n = nums.size();

        long long sum = 0;
        

        sort(nums.begin(), nums.end());

        int i = 0;
        while(i < n - 3)
        {
            int j = i + 1;
            while(j < n - 2)
            {
                int k = j + 1;
                int l = n - 1;
                while( k < l)
                {
                    sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target) k++;

                    else if(sum > target) l--;

                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k - 1]) k++;

                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }

                    
                }
                j++;
                    while(j < n - 2 && nums[j] == nums[j - 1]) j++;
            }
            i++;
            while(i < n - 3 && nums[i] == nums[i - 1]) i++;
        }
        return ans;
    }
};