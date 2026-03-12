1class Solution {
2public:
3    vector<vector<int>> remaining_edges;
4    constexpr inline bool singleComponent(vector<vector<int>> &adj){
5        vector<int> vis(adj.size(), 0);
6
7        auto dfs = [&](auto &&self, int node) -> void{
8            vis[node] = 1;
9            for(auto child : adj[node]){
10                if(!vis[child]){
11                    vis[child] = 1;
12                    self(self, child);
13                }
14            }
15        };
16
17        dfs(dfs,0);
18
19        for(int node : vis){
20            if(!node){
21                return false;
22            }
23        }
24
25        return true;
26    }
27
28    constexpr inline bool f(int n, vector<vector<int>> &edges, int target, int k){
29        // vector<vector<int>> remaining_edges;
30        vector<int> parent(n, -1);
31        int min_strength = 2e5;
32
33        auto find_ = [&](auto &&self, int x) -> int{
34            return parent[x] < 0 ? x : parent[x] = self(self, parent[x]);
35        };
36
37        auto merge_ = [&](int u, int v) -> bool{
38            u = find_(find_,u), v = find_(find_,v);
39            if(u == v) return false;
40
41            if(u < v){
42                parent[v] = u;
43            }else if(v < u){
44                parent[u] = v;
45            }else{
46                parent[v] = u;
47                parent[u]--;
48            }
49
50            return true;
51        };
52
53        int edge_count = 0;
54        for(auto edge : edges){
55            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];
56            if(must){
57                min_strength = min(min_strength, s);
58                if(min_strength < target) return false;
59                merge_(u,v);
60                edge_count++;
61                // cout << edge_count << endl;
62                if(edge_count > n-1) return false;
63            }
64            // }else{
65            //     remaining_edges.emplace_back(edge);
66            // }
67        }
68
69
70
71        // sort(remaining_edges.begin(), remaining_edges.end(), [&](vector<int> &a, vector<int> &b){
72        //     return a[2] > b[2];
73        // });
74
75        for(auto remaining_edge : remaining_edges){
76            int u = remaining_edge[0], v = remaining_edge[1], s = remaining_edge[2];
77            // cout << "At " << u << "," << v << " -> ";
78            if(merge_(u,v)){
79                // cout << s << "," << k << " -> ";
80                edge_count++;
81                if(edge_count > n-1) return false;
82                if(s < target){
83                    if(!k or s*2 < target) return false;
84                    k--;
85                }
86
87                // cout << k << endl;   
88            }
89            // cout << endl;
90        }
91
92        return true;
93    }
94
95    int maxStability(int n, vector<vector<int>>& edges, int k) {
96        vector<vector<int>> adj(n, vector<int> {});
97        for(auto edge : edges){
98            int u = edge[0], v = edge[1];
99            adj[u].push_back(v);
100            adj[v].push_back(u);
101            if(!edge.back()) remaining_edges.emplace_back(edge);
102        }
103
104        if(!singleComponent(adj)) return -1;
105
106        sort(remaining_edges.begin(), remaining_edges.end(), [&](vector<int> &a, vector<int> &b){
107            return a[2] > b[2];
108        });
109
110        int left = 0, right = 2e5;
111        while(left <= right){
112            int mid = left + ((right-left)>>1);
113
114            if(f(n,edges,mid,k)){
115                left = mid+1;
116            }else{
117                right = mid-1;
118            }
119        }
120
121        // for(int i = 0; i < 10; i++){
122        //     cout << i << " : " << f(n,edges,i,k) << endl;
123        // }
124        return (right == 0 ? -1 : right);
125    }
126};