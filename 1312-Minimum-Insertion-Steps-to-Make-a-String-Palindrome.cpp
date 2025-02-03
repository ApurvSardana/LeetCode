class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        //dp[i][j] stores the min insertion steps for the substring s[i..j]
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));


        for(int i = 0; i < n; i++){
            dp[i][i] = 0;

            if(i < n-1){
                if(s[i] == s[i+1])
                    dp[i][i+1] = 0;
                
                else
                    dp[i][i+1] = 1;
            }
        }

        for(int length = 3; length <= n; length++){
            for(int i = 0; i <= n - length; i++){
                int j = i + length - 1;

                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                
                else
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};