class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> before(n, 0), after(n, 0);

        //Count no. of consecutive ones before index i
        int count = 0;
        for(int i = 0; i < n; i++){
            before[i] = count;

            count += (nums[i] ? 1 : -count);
        }

        //Count no. of consecutive ones after index i
        count = 0;
        for(int i = n-1; i >= 0; i--){
            after[i] = count;

            count += (nums[i] ? 1 : -count);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, before[i]+after[i]);
        }

        return ans;
    }
};