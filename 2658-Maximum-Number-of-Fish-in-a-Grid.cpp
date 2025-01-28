class Solution {
public:
    int m, n;
    int bfs(const int &row, const int &column, const vector<vector<int>> &grid){
        queue<pair<int, int>> q;
        int ans = 0;
        q.push({row, column});
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!q.empty()){
            pair<int, int> p = q.front();
            int r = p.first; int c = p.second;
            visited[r][c] = true;
            q.pop();

            ans += grid[r][c];

            //Top Check
            if(r > 0 && grid[r - 1][c] != 0 && !visited[r - 1][c]){
                visited[r - 1][c] = true;
                q.push({r - 1, c});
            }
            
            //Right Check
            if(c < n - 1 && grid[r][c + 1] != 0 && !visited[r][c + 1]){
                visited[r][c + 1] = true;
                q.push({r, c + 1});
            }
            
            //Bottom check
            if(r < m - 1 && grid[r + 1][c] != 0 && !visited[r + 1][c]){
                visited[r + 1][c] = true;
                q.push({r + 1, c});
            }

            //Left Check
            if(c > 0 && grid[r][c - 1] != 0 && !visited[r][c - 1]){
                visited[r][c - 1] = true;
                q.push({r, c - 1});
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = INT_MIN;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] != 0)
                    ans = max(ans, bfs(i, j, grid));
        
        return (ans == INT_MIN) ? 0 : ans;
    }
};