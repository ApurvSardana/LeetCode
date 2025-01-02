class Solution {
public:
    int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        distance[0] = 0;
        ways[0] = 1;

        vector<vector<pair<int, int>>> adj(n); // Adjacency list
        for (auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist > distance[node]) continue; // Skip outdated pairs

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (dist + edgeWeight < distance[nextNode]) {
                    distance[nextNode] = dist + edgeWeight;
                    pq.push({distance[nextNode], nextNode});
                    ways[nextNode] = ways[node];
                } else if (dist + edgeWeight == distance[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return distance[n - 1] == LLONG_MAX ? 0 : ways[n - 1];
    }
};
