class Solution {
public:
    const int MOD = 1E9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        //dp[i] stores number of subarrays ending at i with odd sum
        vector<int> dp(n, 0);

        for(int i = 0; i < n; i++)
            dp[i] = arr[i] & 1;

        for(int i = 1; i < n; i++){
            if(arr[i] & 1)
                dp[i] += i - dp[i-1];

            else
                dp[i] += dp[i-1];
        }
        long long ans = 0;
        for(int i : dp)
            ans = (ans + i)%MOD;

        return (int)ans;
    }
};