class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0; int n = nums.size();
        int l = 0; int r = 0;

        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> m;
        while(r < n){
            m[nums[r]]++;

            while(l <= r && m[maxi] >= k){
                ans += n-r;
                m[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};