class Solution {
public:
    typedef struct{
        int x, y;
        long long mask;
        int e;
    }State;
    
    int minMoves(vector<string>& classroom, int energy) {
        const int m = classroom.size(); const int n = classroom[0].length();
        bool vis[20][20][1 << 10][51];
        memset(vis, 0, sizeof(vis));
        map<pair<int, int>, int> lit_id;
        int index = 0;
        State start;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(classroom[i][j] == 'S'){
                    start.x = i;
                    start.y = j;
                    start.mask = 0;
                    start.e = energy;
                    vis[i][j][0][energy] = true;
                }

                else if(classroom[i][j] == 'L'){
                    lit_id[{i, j}] = index++;
                }
            }
        }
        //cout << (1 << index)-1 << endl;
        queue<pair<State, int>> q;
        q.push({start, 0});
        while(!q.empty()){
            auto [S, dis] = q.front(); q.pop();

            int x = S.x, y = S.y; //cout << x << " " << y << endl;
            long long mask = S.mask; //cout << mask << endl;
            int e = S.e;
            if(mask == (1 << index) - 1) return dis;
            if(e == 0) continue;

            int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            for(int i = 0; i < 4; i++){
                int nx = x+dir[i][0], ny = y+dir[i][1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X') continue;

                State nS;
                nS.x = nx; nS.y = ny;
                nS.mask = mask;
                if(classroom[nx][ny] == 'L') nS.mask |= (1 << lit_id[{nx, ny}]);
                nS.e = e-1;
                if(classroom[nx][ny] == 'R') nS.e = energy;

                if(!vis[nx][ny][nS.mask][nS.e]){
                    vis[nx][ny][nS.mask][nS.e] = true;
                    q.push({nS, dis+1});
                }
            }
        }

        return -1;
    }
};