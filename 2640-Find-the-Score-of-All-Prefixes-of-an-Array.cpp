class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int size = nums.size();
        vector<int> maxArray;
        int max = INT_MIN;
        for(const auto &n : nums)
        {
            if(n > max)
            max = n;

            maxArray.push_back(max);
        }

        vector<long long> conver;

        for(int i = 0; i < nums.size(); i++)
        conver.push_back(nums[i] + maxArray[i]);


        long long sum = 0;

        vector<long long> ans;
        for(int i = 0; i < size; i++)
        {
            sum = sum + conver[i];
            ans.push_back(sum);
        }
    return ans;
    }
};