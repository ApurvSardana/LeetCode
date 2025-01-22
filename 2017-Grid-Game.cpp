class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefix1(n, 0), prefix2(n + 1, 0);

        prefix1[0] = grid[0][0];
        prefix2[0] = 0;
        prefix2[1] = grid[1][0];

        for(int i = 1; i < n; i++){
            prefix1[i] = prefix1[i - 1] + grid[0][i];
            prefix2[i + 1] = prefix2[i] + grid[1][i];
        }

        long long ans = (long long)1e10;
        for(int i = 0; i < n; i++)
            ans = min(ans, max(prefix1[n - 1] - prefix1[i], prefix2[i]));

        return ans;
    }
};