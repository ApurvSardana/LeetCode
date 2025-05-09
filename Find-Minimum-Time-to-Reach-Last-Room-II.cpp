class State{
    public:
        int x;
        int y;
        int distance;

        State(int x, int y, int dis) : x(x), y(y), distance(dis) {};
        void setState(int x, int y, int dis){
            this -> x = x;
            this -> y = y;
            this -> distance = dis;
        }
};

struct comp{
    bool operator()(State &a, State &b){
        return a.distance > b.distance;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(); int m = moveTime[0].size();

        vector<vector<State>> s(n, vector<State>(m, {0, 0, 0}));

        for(int i = 0;i < n; i++)
            for(int j = 0; j < m; j++)
                s[i][j].setState(i, j, INT_MAX);
        s[0][0].distance = 0;

        int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        
        priority_queue<State, vector<State>, comp> pq;
        pq.push(s[0][0]);

        while(!pq.empty()){
            State u = pq.top();
            pq.pop();
            int x = u.x, y = u.y, dis = u.distance;

            if(x == n-1 && y == m-1){
                return dis;
            }

            for(int i = 0;i < 4; i++){
                int nx = x+dir[i][0];
                int ny = y+dir[i][1];

                if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) continue;

                if((x+y)%2 == 0 && s[nx][ny].distance > max(0, moveTime[nx][ny]-dis)+1+dis){
                    s[nx][ny].distance = max(0, moveTime[nx][ny]-dis)+1+dis;
                    pq.push(s[nx][ny]);
                }

                else if((x+y)%2 != 0 && s[nx][ny].distance > max(0, moveTime[nx][ny]-dis)+2+dis){
                    s[nx][ny].distance = max(0, moveTime[nx][ny]-dis)+2+dis;
                    pq.push(s[nx][ny]);
                }
            }
        }

        return s[n-1][m-1].distance;
    }
};