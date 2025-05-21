class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for(int i = 0; i < m; i++){
            if(rows[i]){
                for(int c = 0; c < n; c++){
                    matrix[i][c] = 0;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(cols[i]){
                for(int r = 0; r < m; r++){
                    matrix[r][i] = 0;
                }
            }
        }
    }
};