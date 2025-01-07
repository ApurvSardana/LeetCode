class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto v : times)
            adj[v[0]].push_back({v[1], v[2]});

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            for(auto v : adj[node])
            {
                int ew = v.second;
                int adjacent = v.first;

                if(distance[node] + ew < distance[adjacent])
                {
                    distance[adjacent] = distance[node] + ew;
                    pq.push({distance[adjacent], adjacent});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++)
            ans = max(ans, distance[i]);
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};