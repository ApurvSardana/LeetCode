class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(); int n = grid[0].size();
        vector<int> a;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a.push_back(grid[i][j]);

        sort(a.begin(), a.end());
        int val = a[m*n/2];

        int ans = 0;
        for(int i = 0; i < m*n; i++){
            int diff = abs(a[i]-val);
            if(diff%x != 0)
                return -1;
            
            ans += diff/x;
        }
        return ans;
    }
};