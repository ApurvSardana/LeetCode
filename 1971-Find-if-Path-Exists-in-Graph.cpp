class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(source);

        if(source == destination) return true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            visited[node] = true;

            for(auto neighbor : adj[node])
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    if(neighbor == destination)
                        return true;
                    
                    q.push(neighbor);
                }
        }
        return false;
    }
};