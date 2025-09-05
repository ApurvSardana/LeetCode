class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        //ss[i] represents sum of all starting from and including element at i till end
        vector<int> ss(n, nums[n-1]);

        for(int i = n-2; i >= 0; i--){
            ss[i] = ss[i+1] + nums[i];
        }

        // for(int i = 0; i < n; i++){
        //     cout << ss[i] << ", ";
        // }

        // cout << endl;

        int ps = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int j = lower_bound(ss.rbegin(), ss.rend(), x-ps)-ss.rbegin();
            j = n-j-1;

            if(ps == x){
                ans = min(ans, i);
            }

            //cout << i << "," << j << " : " << ps << "," << ss[n-j-1] << endl;

            if(j >= i && ss[j] == x-ps){
                // cout << i << "," << j << endl;
                ans = min(ans, n+i-j);
            }

            ps += nums[i];
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};