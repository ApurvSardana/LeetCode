class Solution {
public:
    vector<vector<vector<int>>> adj; int m;
    vector<bool> visited; vector<int> parent;
    vector<int> rank_;

    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void union_(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b)
            return;
        
        else if(rank_[a] > rank_[b])
            parent[b] = a;
        
        else if(rank_[b] > rank_[a])
            parent[a] = b;
        
        else{
            parent[b] = a;
            rank_[a]++;
        }
    }

    int bfs(int source){
        int and_val = INT_MAX;

        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int u = q.front();

            q.pop();
            
            for(auto edge : adj[u]){
                int edge_id = edge[0];
                int v = edge[1];
                int w = edge[2];

                if(!visited[edge_id]){
                    visited[edge_id] = true;
                    and_val = and_val & w;
                    q.push(v);
                }
            }
        }

        return and_val;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        adj.assign(n, {}); m = edges.size();
        parent.assign(n, 0); rank_.assign(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        int count = 0;
        unordered_map<int, int> and_val;

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int edge_id = count++;

            union_(u, v);

            adj[u].push_back({edge_id, v, w});
            adj[v].push_back({edge_id, u, w});
        }

        visited.assign(m, false);
        
        for(int i = 0; i < n; i++){
            if(parent[i] != i)
                continue;
            
            and_val[i] = bfs(i);
        }

        vector<int> ans;
        for(auto q : query){
            int source = q[0];
            int target = q[1];

            int parent_of_source = find(source);
            int parent_of_target = find(target);

            if(parent_of_source == parent_of_target){
                ans.push_back(and_val[parent_of_source]);
            }

            else
                ans.push_back(-1);
        }
        return ans;
    }
};