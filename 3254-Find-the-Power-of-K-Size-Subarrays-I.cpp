class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> results;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++)
        {
            int flag = 0;
            int j = 0;
            for(; j < k - 1; j++)
            {
                if(nums[i + j] != nums[i + j + 1] - 1)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            results.push_back(nums[i + j]);

            else
            results.push_back(-1);
        }
        return results;
    }
};