class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> left_greatest(n, 0), right_greatest(n, 0);
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i - 1]);
            left_greatest[i] = maxi;
        }

        maxi = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxi = max(maxi, nums[i + 1]);
            right_greatest[i] = maxi;
        }

        for (int i = 1; i < n - 1; i++)
            ans = max(ans, (long long)(left_greatest[i] - nums[i]) *
                               right_greatest[i]);

        return ans;
    }
};