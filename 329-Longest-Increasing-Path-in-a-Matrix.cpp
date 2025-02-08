class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>> &matrix, int r, int c){
        int ans = 0;

        //Top Check
        if(r > 0 && matrix[r-1][c] < matrix[r][c]){
            if(dp[r-1][c] != 0)
                ans = max(ans, dp[r-1][c]);
            
            else
                ans = max(ans, dfs(matrix, r-1, c));
        }
        
        //Right Check
        if(c < n-1 && matrix[r][c+1] < matrix[r][c]){
            if(dp[r][c+1] != 0)
                ans = max(ans, dp[r][c+1]);
            
            else
                ans = max(ans, dfs(matrix, r, c+1));
        }

        //Bottom Check
        if(r < m-1 && matrix[r+1][c] < matrix[r][c]){
            if(dp[r+1][c] != 0)
                ans = max(ans, dp[r+1][c]);
            
            else
                ans = max(ans, dfs(matrix, r+1, c));
        }

        //Left Check
        if(c > 0 && matrix[r][c-1] < matrix[r][c]){
            if(dp[r][c-1] != 0)
                ans = max(ans, dp[r][c-1]);
            
            else
                ans = max(ans, dfs(matrix, r, c-1));
        }
        
        return dp[r][c] = 1 + ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));

        int ans = INT_MIN;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] != 0)
                    ans = max(ans, dp[i][j]);
                
                else
                    ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};