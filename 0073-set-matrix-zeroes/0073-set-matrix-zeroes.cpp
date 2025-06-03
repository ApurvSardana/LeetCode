class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        bool fr = false; bool fc = false;

        for(int i = 0; i < n; i++) if(matrix[0][i] == 0) fr = true;
        for(int i = 0; i < m; i++) if(matrix[i][0] == 0) fc = true;
        cout << fr << " " << fc << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int c = 0; c < n; c++){
                    matrix[i][c] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
            if(matrix[0][i] == 0){
                for(int r = 0; r < m; r++){
                    matrix[r][i] = 0;
                }
            }
        }

        if(fr) {
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }

        if(fc) {
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;
        }
    }
};