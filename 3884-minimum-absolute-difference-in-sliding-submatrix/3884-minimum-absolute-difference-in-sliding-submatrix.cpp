class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int> (n-k+1, 0));
        for(int i = 0; i <= m-k; i++){
            for(int j = 0; j <= n-k; j++){
                set<long long> s; s.clear();
                for(int r = i; r <= i+k-1; r++){
                    for(int c = j; c <= j+k-1; c++){
                        s.insert((long long)grid[r][c]);
                    }
                }

                long long diff = LLONG_MAX;
                int size = s.size();
                vector<long long> v(s.begin(), s.end());
                //cout << s.size() << " " << v.size() << endl;
                for(int count = 0; count < size-1; count++){
                    diff = min(diff, abs(v[count] - v[count+1]));
                }

                if(size == 1) ans[i][j] = 0;
                else ans[i][j] = (int)diff;
            }
        }

        return ans;
    }
};