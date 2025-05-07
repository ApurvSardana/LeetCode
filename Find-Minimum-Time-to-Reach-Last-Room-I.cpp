class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(); int m = moveTime[0].size();

        //dp[i][j] represents minimum time to reach cell {i,j} from {0,0}
        vector<vector<long long>> dp(n, vector<long long> (m, INT_MAX));

        dp[0][0] = 0LL;
        for(int k = 0; k<max(n,m); k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    //if(j < i) continue;

                    if(i != 0)
                        dp[i][j] = min(dp[i][j], 1LL + dp[i-1][j]+ (long long)(max(moveTime[i][j]-dp[i-1][j], 0LL)));

                    if(i != n-1)
                        dp[i][j] = min(dp[i][j], 1LL + dp[i+1][j]+ (long long)(max(moveTime[i][j]-dp[i+1][j], 0LL)));
                    
                    if(j != 0)
                        dp[i][j] = min(dp[i][j], 1LL + dp[i][j-1] + (long long)(max(moveTime[i][j]-dp[i][j-1], 0LL)));

                    if(j != m-1)
                        dp[i][j] = min(dp[i][j], 1LL + dp[i][j+1] + (long long)(max(moveTime[i][j]-dp[i][j+1], 0LL)));
                }
            }
        }


        // for(int i = 0; i <n; i++)
        //     for(int j = 0; j<m; j++){
        //         cout << i << ", " << j << " : " << dp[i][j] << endl;
        //     }

        return dp[n-1][m-1];
    }
};