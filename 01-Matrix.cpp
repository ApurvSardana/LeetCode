1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int m = mat.size(), n = mat.front().size();
5        vector<vector<int>> dis(m, vector<int> (n, 1e9));
6
7        queue<tuple<int, int, int>> q;
8
9        for(int i = 0; i < m; i++){
10            for(int j = 0; j < n; j++){
11                if(!mat[i][j]){
12                    dis[i][j] = 0;
13                    q.push({0,i,j});
14                }
15            }
16        }
17
18        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
19        while(!q.empty()){
20            auto [d,r,c] = q.front();
21            q.pop();
22
23            for(int mv = 0; mv < 4; mv++){
24                int nr = r + dir[mv][0], nc = c + dir[mv][1];
25                if(nr < 0 || nr >= m || nc < 0 || nc >= n || dis[nr][nc] < d+1) continue;
26                
27                dis[nr][nc] = d+1;
28                q.push({d+1,nr,nc});
29            }
30        }
31
32        return dis;
33
34    }
35};