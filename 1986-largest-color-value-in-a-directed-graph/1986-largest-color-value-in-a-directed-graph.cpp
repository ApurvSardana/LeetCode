class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();

        vector<vector<int>> dp(n, vector<int> (26, 0));
        vector<vector<int>> adj(n, vector<int> {});
        vector<int> indegree(n, 0);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            dp[i][colors[i]-'a']++;
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0; int ans = 0;
        while(!q.empty()){
            int u = q.front(); count++;
            q.pop();

            for(int i = 0; i < 26; i++)
                ans = max(ans, dp[u][i]);

            for(int v : adj[u]){
                int add = 0;
                for(int i = 0; i < 26; i++){
                    add = colors[v]-'a' == i;
                    dp[v][i] = max(dp[v][i], dp[u][i]+add);
                }

                indegree[v] -= 1;
                if(indegree[v] == 0) q.push(v);
            }
        }

        return count == n ? ans : -1;
    }
};