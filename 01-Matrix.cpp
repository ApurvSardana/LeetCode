1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int m = mat.size(), n = mat.front().size();
5        vector<vector<int>> dis(m, vector<int> (n, 1e9));
6        for(int i = 0; i < m; i++){
7            for(int j = 0; j < n; j++){
8                if(!mat[i][j]) dis[i][j] = 0;
9            }
10        }
11
12        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
13
14        for(int i = 0; i < m; i++){
15            for(int j = 0; j < n; j++){
16                if(!mat[i][j]) pq.push({0,{i,j}});
17            }
18        }
19
20        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
21        while(!pq.empty()){
22            int d = pq.top().first; auto [r,c] = pq.top().second;
23            pq.pop();
24
25            if(dis[r][c] < d) continue;
26
27            for(int mv = 0; mv < 4; mv++){
28                int nr = r + dir[mv][0], nc = c + dir[mv][1];
29                if(nr >= m || nc >= n || nr < 0 || nc < 0) continue;
30                if(dis[nr][nc] > d+1){
31                    dis[nr][nc] = d+1;
32                    pq.push({d+1, {nr,nc}});
33                }
34            }
35        }
36
37        return dis;
38    }
39};