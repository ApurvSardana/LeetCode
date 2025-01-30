class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;

            for(int adj : rooms[node])
                if(!visited[adj]){
                    visited[adj] = true;
                    q.push(adj);
                }
        }

        bool ans = true;
        for(bool b : visited)
            ans &= b;
        
        return ans;
    }
};