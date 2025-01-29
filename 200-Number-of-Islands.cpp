class Solution {
public:
    int m, n;
    void dfs(int r, int c, vector<vector<char>> &grid){
        if(grid[r][c] == '0')
            return;
        
        visited[r][c] = true;

        if(r > 0 && !visited[r-1][c])
            dfs(r-1, c, grid);
        if(r < m - 1 && !visited[r+1][c])
            dfs(r+1, c, grid);
        if(c > 0 && !visited[r][c-1])
            dfs(r, c-1, grid);
        if(c < n - 1 && !visited[r][c+1])
            dfs(r, c+1, grid);
    }
    vector<vector<bool>> visited;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    visited[i][j] = true;
                    dfs(i, j, grid);
                }
            }
        return ans;   
    }
};