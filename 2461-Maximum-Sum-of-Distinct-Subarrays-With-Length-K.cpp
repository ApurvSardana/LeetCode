class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;

        int n = nums.size();

        long long sum = 0;
        map<int, int> m;

        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
            m[nums[i]]++;
        }

        if(m.size() == k)
            ans = max(ans, sum);

        for(int i = k; i < n; i++)
        {
            sum -= nums[i - k];
            sum += nums[i];
            m[nums[i - k]]--;

            if( m[nums[i - k]] == 0)
                m.erase(nums[i - k]);
                
            m[nums[i]]++;

            if(m.size() == k)
                ans = max(ans, sum);
        }
        return ans;
    }
};