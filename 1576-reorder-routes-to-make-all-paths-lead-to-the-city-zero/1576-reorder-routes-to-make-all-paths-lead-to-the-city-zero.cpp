class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj, vector<vector<int>> &rev_adj, vector<bool> &vis){
        vis[node] = true;

        int ans = 0;
        for(auto child : adj[node]){
            if(!vis[child]){
                ans += 1 + dfs(child, adj, rev_adj, vis);
            }
        }

        for(auto parent : rev_adj[node]){
            if(!vis[parent]){
                ans += dfs(parent, adj, rev_adj, vis);
            }
        }

        return ans;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n, vector<int> {});
        vector<vector<int>> rev_adj(n, vector<int> {});

        for(auto connection : connections){
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        return dfs(0, adj, rev_adj, vis);
    }
};