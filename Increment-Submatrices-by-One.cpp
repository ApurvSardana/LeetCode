class Solution {
public:
    int dm[500][501];
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        for(auto &query : queries){
            auto [r1,c1,r2,c2] = array<int, 4>({query[0],query[1],query[2],query[3]});

            for(int r = r1; r <= r2; r++){
                dm[r][c1]++;
            }

            for(int r = r1; r <= r2; r++){
                dm[r][c2+1]--;
            }
        }

        vector<vector<int>> ans(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0) ans[i][j] = dm[i][j];
                else ans[i][j] = ans[i][j-1] + dm[i][j];
            }
        }

        return ans;
    }
};