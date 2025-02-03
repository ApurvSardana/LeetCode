class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();

        //dp[i][j] represents the number of subsequences from s[0...i] that are equal to the substring t[0...j]
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(m, 0));
        dp[0][0] = (s[0] == t[0]) ? 1 : 0;

        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0];

            if(s[i] == t[0])
                dp[i][0]++;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(i == j && s[i] == t[j])
                    dp[i][j] = dp[i-1][j-1];
                
                else if(i > j && s[i] != t[j])
                    dp[i][j] = dp[i-1][j];
                
                else if(i > j && s[i] == t[j])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};