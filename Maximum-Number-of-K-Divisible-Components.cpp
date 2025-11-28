1class Solution {
2public:
3    int ans;
4    vector<vector<int>> adj;
5    using ll = long long;
6    ll dfs(int u, vector<int> &values, vector<bool> &vis, int k){
7        vis[u] = true;
8
9        ll mySum = 0;
10        for(int j : adj[u]){
11            if(!vis[j]){
12                ll sum = dfs(j, values, vis, k);
13                if(sum%k == 0){
14                    ans++;
15                }
16
17                else{
18                    mySum += sum;
19                }
20            }
21        }
22
23        return mySum + values[u];
24    }
25
26    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
27        ans = 0;
28        adj.assign(n, vector<int> {});
29        for(auto edge : edges){
30            adj[edge[0]].push_back(edge[1]);
31            adj[edge[1]].push_back(edge[0]);
32        }
33        vector<bool> vis(n, false);
34        ll x = dfs(0, values, vis, k);
35
36        return ans+1;
37    }
38};