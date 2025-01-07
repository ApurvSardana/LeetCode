class Graph {
public:
    int nodes;
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        adj.assign(n, {});
        for(auto v : edges)
            adj[v[0]].push_back({v[1], v[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int source = node1;
        vector<int> distance(nodes, INT_MAX);
        distance[source] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, source});

        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for(auto p : adj[u])
            {
                int ew = p.second;
                int v = p.first;
                if(distance[u] + ew < distance[v])
                {
                    distance[v] = distance[u] + ew;
                    pq.push({distance[v], v});
                }
            }
        }
        return (distance[node2] == INT_MAX) ? -1 : distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */