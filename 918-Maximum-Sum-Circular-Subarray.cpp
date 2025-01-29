class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        //Kadane on the normal array.
        int ans = INT_MIN; int sum = 0;
        int total_sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, sum);

            if(sum < 0)
                sum = 0;
            
            total_sum += nums[i];
            nums[i] = -nums[i];
        }

        int ans1 = ans;
        // for(int i : nums)
        //     cout << i << " ";
        
        //Kadane on the negative array
        ans = INT_MIN; sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, sum);

            if(sum < 0)
                sum = 0;
        }
        int s = ans;
        cout << -s;
        int ans2 = total_sum + ans;

        // cout << ans1 << " " << ans2
        return (ans2 == 0) ? ans1 : max(ans1, ans2);
    }
};