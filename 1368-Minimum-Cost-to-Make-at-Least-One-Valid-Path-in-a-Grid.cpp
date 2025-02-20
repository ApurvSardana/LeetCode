class Solution {
public:
    int m, n;
    int dijkstra(int source, vector<vector<pair<int, int>>> &adj){
        vector<int> distance(n*m, INT_MAX);
        vector<bool> visited(n*m, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, source});

        while(!pq.empty()){
            
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(visited[node])
                continue;

            visited[node] = true;

            for(auto p : adj[node]){
                int adjacent = p.first;
                if(distance[adjacent] > dis + p.second){
                    distance[adjacent] = dis + p.second;
                    pq.push({distance[adjacent], adjacent});
                }
            }
        }
        return distance[n*m - 1];
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(n*m == 1)
            return 0;

        vector<vector<pair<int, int>>> adj(n*m, vector<pair<int, int>> ({}));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int node = n*i + j;
                int val = grid[i][j];
                //Right Check
                if(j < n-1 && val != 1)
                    adj[node].push_back({node+1, 1});

                else if(j < n-1)
                    adj[node].push_back({node+1, 0});
                
                
                //Left Check
                if(j > 0 && val != 2)
                    adj[node].push_back({node-1, 1});

                else if(j > 0)
                    adj[node].push_back({node-1, 0});
                
                //Down Check
                if(i < m-1 && val != 3)
                    adj[node].push_back({node+n, 1});

                else if(i < m-1)
                    adj[node].push_back({node+n, 0});
                
                //Up Check
                if(i > 0 && val != 4)
                    adj[node].push_back({node-n, 1});

                else if(i > 0)
                    adj[node].push_back({node-n, 0});
            }
        }

        return dijkstra(0, adj);
    }
};