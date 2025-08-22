class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.front().size();

        vector<vector<int>> pzi(m, vector<int> (n, -1));
        for(int i = 0; i < m; i++){
            int prev = (mat[i][0] == 0) ? 0 : -1;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    prev = j;

                pzi[i][j] = prev;
                //cout << pzi[i][j] << ", ";
            }
            //cout << endl;
        } 

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    int mn = j-pzi[i][j];

                    for(int k = i; k >= 0; k--){
                        mn = min(mn, j-pzi[k][j]);
                        ans += mn;
                    }
                }
            }
        }

        return ans;
    }
};