class Solution {
public:
    int bfs(vector<vector<int>> &adj, int source, int target_distance, int n){
        queue<int> q;
        q.push(source); int curr_distance = 0;
        q.push(-1); int ans = 0; vector<bool> vis(n, false);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u != -1){
                vis[u] = true;
                if(curr_distance <= target_distance) ans++;
                else break;

                for(int v : adj[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            else{
                curr_distance++;
                if(!q.empty() && curr_distance <= target_distance) q.push(-1);
                else break;
            }
        }

        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n, vector<int> {}), adj2(m, vector<int> {});

        for(auto edge : edges1){
            int u = edge[0], v = edge[1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto edge : edges2){
            int u = edge[0], v = edge[1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int> answers(n, 0);
        for(int i = 0; i < n; i++){
            answers[i] += bfs(adj1, i, k, n);
        }
        
        int mx = 0;
        for(int i = 0; i < m; i++){
            mx = max(mx, bfs(adj2, i, k-1, m));
        }

        for(int i = 0; i < n; i++)
            answers[i] += mx;

        return answers;
    }
};