1class Solution {
2public:
3    long long maxSubarraySum(vector<int>& nums, int k) {
4        int n = nums.size();
5        // dp[i] represents the max subarray sum, ending at index i such that length is divisible by k
6        vector<long long> ps(n+1, 0), dp(n, 0);
7
8        for(int i = 0; i < n; i++)
9        {
10            ps[i+1] = ps[i] + nums[i];
11        }
12
13        dp[k-1] = ps[k];
14
15        for(int i = k; i < n; i++)
16        {
17            dp[i] = ps[i+1] - ps[i-k+1] + max(0LL, dp[i-k]);
18        }
19
20        return *max_element(dp.begin()+k-1, dp.end());
21    }
22};