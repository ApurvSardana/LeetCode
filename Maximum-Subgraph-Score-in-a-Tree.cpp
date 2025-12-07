1class Solution {
2public:
3    int dfs(int n, vector<vector<int>> &adj, int u, int parent, vector<int> &good, vector<int> &down){
4        if(!good[u]) down[u] = -1;
5        // if(u == 0) cout << down[u] << endl;
6        for(int v : adj[u]){
7            if(v != parent){
8                down[u] += max(0, dfs(n,adj,v,u,good,down));
9                // if(u == 0) cout << down[u] << endl;
10            }
11        }
12
13        return down[u];
14    }
15
16    void dfs2(int n, vector<vector<int>> &adj, int u, int parent, vector<int> &good, vector<int> &down, vector<int> &total, vector<bool> &vis){
17        if(!vis[u]){
18            int temp1 = down[u];
19            int temp2 = total[parent];
20            if(temp1 < 0) temp2 += (good[u] ? 1 : -1);
21
22            total[u] = max(temp1, temp2);
23            vis[u] = true;
24        }
25
26        for(int v : adj[u]){
27            if(v != parent){
28                dfs2(n,adj,v,u,good,down,total,vis);
29            }
30        }
31    }
32
33    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
34        vector<vector<int>> adj(n, vector<int> {});
35        for(auto &edge : edges){
36            adj[edge[0]].push_back(edge[1]);
37            adj[edge[1]].push_back(edge[0]);
38        }
39
40        vector<int> down(n, 1);
41        down[0] = dfs(n, adj, 0, -1, good, down);
42
43        vector<int> total(down.begin(), down.end());
44        vector<bool> vis(n, false);
45        vis[0] = true;
46
47        dfs2(n,adj,0,-1,good,down,total,vis);
48
49        return total;
50    }
51};