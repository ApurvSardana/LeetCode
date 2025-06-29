class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (op1+1, vector<int> (op2+1, 0)));

        for(int i = 1; i <= n; i++){
            for(int o1 = 0; o1 <= op1; o1++){
                if(o1 > i) continue;
                for(int o2 = 0; o2 <= op2; o2++){
                    if(o2 > i) continue;
                    dp[i][o1][o2] = dp[i-1][o1][o2];

                    if(o1 > 0) dp[i][o1][o2] = max(dp[i][o1][o2], dp[i-1][o1-1][o2] + nums[i-1]/2);

                    if(k <= nums[i-1]){
                        if(o2 > 0) dp[i][o1][o2] = max(dp[i][o1][o2], dp[i-1][o1][o2-1] + k);
                        if(o1 > 0 && o2 > 0){
                            int loss = nums[i-1]/2;
                            if(nums[i-1]-loss >= k) loss += k;
                            dp[i][o1][o2] = max(dp[i][o1][o2], dp[i-1][o1-1][o2-1]+loss);

                            int loss2 = k;
                            loss2 += (nums[i-1]-k)/2;
                            dp[i][o1][o2] = max(dp[i][o1][o2], dp[i-1][o1-1][o2-1]+loss2);
                        }
                    }
                }
            }
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = sum;
        for(int index = 1; index <= n; index++){
            for(int i = 0; i <= op1; i++){
                for(int j = 0; j <= op2; j++){
                    //cout << dp[index][i][j] << ", ";
                    ans = min(ans, sum-dp[index][i][j]);
                }
                //cout << endl;
            }
            //cout << endl << endl;
        }

        return ans;
    }
};