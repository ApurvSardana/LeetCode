1class Solution {
2public:
3    struct state{
4        int x;
5        int y;
6        int XOR;
7
8        state(int x_, int y_, int XOR_): x(x_), y(y_), XOR(XOR_) {};
9    };
10
11    int minCost(vector<vector<int>>& grid) {
12        int m = grid.size(), n = grid.front().size();
13
14        auto vis = vector<vector<vector<bool>>> (m, vector<vector<bool>> (n, vector<bool> ((1<<10), false)));
15
16        queue<state> q;
17        q.push(state(0,0,grid[0][0]));
18        vis[0][0][grid[0][0]] = true;
19
20        int dir[2][2] = {{1,0}, {0,1}};
21
22        while(!q.empty()){
23            auto curr_state = q.front();
24            q.pop();
25
26            int x = curr_state.x, y = curr_state.y, XOR = curr_state.XOR;
27
28            for(int d = 0; d < 2; d++){
29                int nx = x + dir[d][0], ny = y + dir[d][1];
30                if(nx >= m or ny >= n) continue;
31
32                int nXOR = XOR^grid[nx][ny];
33
34                if(vis[nx][ny][nXOR]) continue;
35
36                vis[nx][ny][nXOR] = true;
37                q.push(state(nx,ny,nXOR));
38            }    
39        }
40
41        for(int x = 0; x < (1<<10); x++){
42            if(vis[m-1][n-1][x] == true) return x;
43        }
44
45        return -1;
46    }
47};