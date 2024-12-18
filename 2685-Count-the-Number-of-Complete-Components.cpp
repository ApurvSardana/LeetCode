class Solution {
public:
    pair<int, int> bfs(int s, vector<vector<int>>& adj, vector<bool> &visited)
    {
        int nodes = 0;
        int edges = 0;

        queue<int> q;
        q.push(s);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            nodes++;
            visited[node] = true;
            
            for(int i : adj[node])
            {
                if(i > node)
                    edges++;

                if(visited[i] == false)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        return {nodes, edges};
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);


        //Create an adjacency list for traversing the graph
        for(auto p : edges)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        //Traverse each component of the graph in Breadth-First fashion
        //and each tracersal would return the number of nodes and edges in
        //the component. 
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == true)
                continue;

            pair<int, int> NE;
            NE = bfs(i, adj, visited);

            int nodes = NE.first;
            int edges_ = NE.second;

            //Checking if the component is complete
            if(edges_ == (nodes * (nodes - 1)) / 2)
                ans++;
        }

        return ans;
    }
};