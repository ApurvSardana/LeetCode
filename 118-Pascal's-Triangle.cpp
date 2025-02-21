class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows, vector<int>(numRows, 0));
        dp[0][0] = 1;

        for(int i = 1; i < numRows; i++)
            for(int j = 0; j < numRows; j++){
                if(j == 0)
                    dp[i][j] = 1;
                
                else
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        
        for(int i = 0; i < numRows; i++)
            dp[i].resize(i+1);

        return dp;
    }
};