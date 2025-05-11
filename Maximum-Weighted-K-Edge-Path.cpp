class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int, int>>> adj(n);
        int ans = INT_MIN;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        vector<vector<set<int>>> dp(n, vector<set<int>> (k+1));

        for(int i = 0; i<n; i++){
            dp[i][0].insert(0);
        }

        for(int u = 0; u<n ;u++){
            for(auto j : adj[u]){
                int v = j.first;
                int w = j.second;

                for(int e = 0; e < k; e++){
                    for(int sum : dp[u][e]){
                        if(sum+w < t)
                            dp[v][e+1].insert(sum+w);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
            if(!dp[i][k].empty())
                ans = max(ans, *max_element(dp[i][k].begin(), dp[i][k].end()));
        
        return ans == INT_MIN ? -1 : ans;
    }
};