class Solution {
public:
    bool bfs(vector<vector<int>> &adj, int source, vector<bool> &visited){
        visited[source] = true;
        queue<int> q;
        q.push(source);
        int nodes = 0, edges = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            nodes++;

            for(int v : adj[u]){
                edges++;
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return edges == nodes*(nodes-1);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            if(!visited[i] && bfs(adj, i, visited))
                ans++;

        return ans;
    }
};