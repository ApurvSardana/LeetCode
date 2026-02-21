1class Solution {
2public:
3    int trapRainWater(vector<vector<int>>& heightMap) {
4        int m = heightMap.size(), n = heightMap.front().size();
5        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
6
7        vector<vector<bool>> vis(m, vector<bool> (n, false));
8        for(int j = 0; j < n; j++){
9            pq.push({heightMap[0][j], {0,j}});
10            if(m != 1) pq.push({heightMap[m-1][j], {m-1,j}});
11            vis[0][j] = vis[m-1][j] = true;
12        }
13
14        for(int i = 1; i < m-1; i++){
15            pq.push({heightMap[i][0], {i,0}});
16            if(n != 1) pq.push({heightMap[i][n-1], {i,n-1}});
17            vis[i][0] = vis[i][n-1] = true;
18        }
19
20        int ans = 0;
21        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
22        while(!pq.empty()){
23            int h = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
24            pq.pop();
25
26            for(int i = 0; i < 4; i++){
27                int nr = r+dir[i][0], nc = c+dir[i][1];
28                if(nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc]) continue;
29
30                if(heightMap[nr][nc] < h){
31                    ans += h-heightMap[nr][nc];
32                }
33
34                pq.push({max(h,heightMap[nr][nc]), {nr,nc}});
35                vis[nr][nc] = true;
36            }
37        }
38
39        return ans;
40    }
41};