class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++)
            dp[n-1][i] = matrix[n-1][i];
        
        for(int i = n-2; i >= 0; i--)
            for(int j = 0; j < n; j++){
                int a = INT_MAX; int b = INT_MAX; int c = INT_MAX;

                //Left Diagonal Check
                if(j > 0)
                   a = dp[i+1][j-1];
                
                //Bottom Check
                b = dp[i+1][j];

                //Right Diagonal Check
                if(j < n-1)
                    c = dp[i+1][j+1];
                
                dp[i][j] = min(a, min(b, c)) + matrix[i][j];    
            }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};