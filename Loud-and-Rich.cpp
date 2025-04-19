class Solution {
public:
    vector<bool> visited;
    int dfs(int source, vector<vector<int>> &adj, vector<int> &quiet, int ra){
        visited[source] = true;
        for(int child : adj[source]){
            if(!visited[child]){
                visited[child] = true;
                int ans = dfs(child, adj, quiet, ra);
                if(quiet[ans] <= quiet[ra]){
                    ra = ans;
                }   
            }
        }

        if(quiet[source] <= quiet[ra]){
            ra = source;
        }

        return ra;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n, vector<int> {});
        vector<int> ans;

        for(auto p : richer){
            int from = p[1];
            int to = p[0];

            adj[from].push_back(to);
        }

        for(int i = 0; i < n; i++){
            visited.assign(n, false);
            ans.push_back(dfs(i, adj, quiet, i));
        }

        return ans;
    }
};