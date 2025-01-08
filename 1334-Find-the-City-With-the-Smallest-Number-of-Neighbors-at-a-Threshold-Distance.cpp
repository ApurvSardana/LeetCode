class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> distance;

    vector<int> dijkstra(const int &n, const int &k)
    {
        vector<int> neighbors(n, 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                distance[i].push_back(INT_MAX);
        
        for(int i = 0; i < n; i++)
        {
            int source = i;
            vector<int> d = distance[source];
            d[source] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            pq.push({0, source});

            while(!pq.empty())
            {
                int node = pq.top().second;
                pq.pop();

                for(auto p : adj[node])
                {
                    int adjacent = p.first;
                    int ew = p.second;

                    if(d[node] + ew < d[adjacent])
                    {
                        d[adjacent] = d[node] + ew;
                        pq.push({d[adjacent], adjacent});
                    }

                }
            }

            for(int i = 0; i < n; i++)
            {
                if(i == source) continue;

                if(d[i] <= k)
                    neighbors[source]++;
            }
        }
        return neighbors;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj.assign(n, {});
        distance.assign(n, {});

        for(auto v : edges)
        {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        vector<int> neighbors = dijkstra(n, distanceThreshold);

        // for(int i = 0; i < n; i++)
        //     cout << i << " : " << neighbors[i] << endl; 

        int number = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(neighbors[i] <= number)
            {
                ans = i;
                number = neighbors[i];
            }

        return ans;
    }
};