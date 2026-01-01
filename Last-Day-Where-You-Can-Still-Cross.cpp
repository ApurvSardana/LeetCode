1class Solution {
2public:
3    bool f(int day, vector<vector<int>> &cells, int row, int col){
4        vector<vector<int>> grid(row, vector<int> (col, 0));
5
6        for(int i = 0; i < day; i++){
7            grid[cells[i][0]-1][cells[i][1]-1] = 1;
8        }
9
10        vector<vector<bool>> dp(row, vector<bool> (col, false)), vis(row, vector<bool> (col, false));
11        queue<pair<int, int>> q;
12        for(int i = 0; i < col; i++){
13            dp[row-1][i] = (grid[row-1][i] == 0);
14            if(dp[row-1][i]){
15                q.push({row-1,i});
16                vis[row-1][i] = true;
17            }
18        }
19
20        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
21        while(!q.empty()){
22            auto [r,c] = q.front();
23            q.pop();
24
25            for(int d = 0; d < 4; d++){
26                int nr = r+dir[d][0], nc = c+dir[d][1];
27                if(nr < 0 || nc < 0 || nr >= row || nc >= col || vis[nr][nc] || grid[nr][nc] == 1) continue;
28                vis[nr][nc] = true;
29                dp[nr][nc] = true;
30                q.push({nr,nc});
31            }
32        }
33
34        for(int i = 0; i < col; i++)
35            if(dp[0][i])
36                return true;
37        
38        return false;
39    }
40    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
41        int total_days = cells.size();
42
43        int left = 0, right = total_days-1;
44        while(left <= right){
45            int mid = left + (right-left)/2;
46            if(f(mid,cells,row,col)){
47                left = mid+1;
48            }
49
50            else{
51                right = mid-1;
52            }
53        }
54
55        return right;
56    }
57};