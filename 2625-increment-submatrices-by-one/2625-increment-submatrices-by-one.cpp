class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pm(n+1, vector<int> (n+1, 0));

        for(auto query : queries){
            int row1 = query[0], col1 = query[1], row2 = query[2], col2 = query[3];

            for(int row = row1; row <= row2; row++){
                pm[row][col1] += 1;
                pm[row][col2+1] -= 1;
            }
        }

        vector<vector<int>> ans(n, vector<int> (n, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0) ans[i][j] = pm[i][j];

                else{
                    ans[i][j] = ans[i][j-1] + pm[i][j];
                }
            }
        }

        return ans;
    }
};