class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        //dp[i] stores the longest window starting at i such that AND of the window is equal to nums[i]
        vector<int> dp(n, 1);
        int mx = *max_element(nums.begin(), nums.end());

        for(int i = n-2; i >= 0; i--){
            //cout << i << " : " << (dp[i]&dp[i+1]) << endl;
            dp[i] = ((nums[i]&nums[i+1]) == mx) ? 1+dp[i+1] : 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};