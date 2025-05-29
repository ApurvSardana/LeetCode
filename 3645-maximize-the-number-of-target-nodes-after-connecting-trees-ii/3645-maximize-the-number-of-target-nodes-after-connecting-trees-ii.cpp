class Solution {
public:
    unordered_set<int> s1, s2, s3, s4;
    void bfs(vector<vector<int>> &adj, int source, int n, bool tree){
        queue<int> q;

        q.push(source);
        q.push(-1); vector<bool> vis(n, false);
        bool flag = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u != -1){
                vis[u] = true;
                if(tree && flag) s1.insert(u);
                else if(tree && !flag) s2.insert(u);
                else if(!tree && flag) s3.insert(u);
                else s4.insert(u);

                for(int v : adj[u])
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
            }

            else{
                flag = !flag;
                if(!q.empty()) q.push(-1);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1, m = edges2.size()+1;
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

        bfs(adj1, 0, n, true);
        bfs(adj2, 0, m, false);

        int n1 = s1.size(), n2 = s2.size(), n3 = max(s3.size(), s4.size());

        vector<int> answer(n, 0);
        for(int i : s1) answer[i] = n1 + n3;
        for(int i : s2) answer[i] = n2 + n3;

        return answer;
    }
};