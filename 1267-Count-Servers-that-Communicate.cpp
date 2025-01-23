class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> serversInRow(m, 0), serversInColumn(n, 0);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1){
                    serversInRow[i]++;
                    serversInColumn[j]++;
                }
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1 && (serversInRow[i] > 1 || serversInColumn[j] > 1))
                    ans++;

        return ans;
    }
};