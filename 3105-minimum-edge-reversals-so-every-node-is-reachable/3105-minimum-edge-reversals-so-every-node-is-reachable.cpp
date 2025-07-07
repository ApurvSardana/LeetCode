class Solution {
public:
    vector<bool> vis;
    vector<int> dp;
    int dfs(int node, vector<vector<int>> &adj, vector<vector<int>> &rev_adj, vector<unordered_map<int, int>> &reversal){
        vis[node] = true;

        dp[node] = 0;
        for(auto child : adj[node]){
            if(!vis[child]){
                reversal[node][child] = dfs(child, adj, rev_adj, reversal);
                dp[node] += reversal[node][child];
            }
        }

        for(auto parent : rev_adj[node]){
            if(!vis[parent]){
                reversal[node][parent] = 1 + dfs(parent, adj, rev_adj, reversal);
                dp[node] += reversal[node][parent];
            }
        }

        return dp[node];
    }

    void set_dps(int node, vector<vector<int>> &adj, vector<vector<int>> &rev_adj, vector<unordered_map<int, int>> &reversal){
        vis[node] = true;
        for(auto child : adj[node]){
            if(!vis[child]){
                dp[child] += 1 + dp[node] - reversal[node][child];
                set_dps(child, adj, rev_adj, reversal);
            }
        }

        for(auto parent : rev_adj[node]){
            if(!vis[parent]){
                dp[parent] += dp[node] - reversal[node][parent];
                set_dps(parent, adj, rev_adj, reversal);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>{}), rev_adj(n, vector<int>{});

        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }
        
        dp.assign(n, 0);
        vector<unordered_map<int, int>> reversal(n);
        vis.assign(n, false);
        dp[0] = dfs(0, adj, rev_adj, reversal);
        
        vis.assign(n, false);
        set_dps(0, adj, rev_adj, reversal);
        return dp;
    }
};