class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        unordered_map<int, pair<int, int>> mp;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                mp[mat[i][j]] = {i, j};
        
        vector<int> rowCount(m, 0);
        vector<int> columnCount(n, 0);

        for(int i = 0; i < m*n; i++)
        {
            rowCount[mp[arr[i]].first]++;
            columnCount[mp[arr[i]].second]++;

            if(rowCount[mp[arr[i]].first] == n || columnCount[mp[arr[i]].second] == m)
                return i;
        }
        return 0;
    }
};