class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    bool dfs(int source, int target)
    {
        int ans = false;
        visited[source] = true;

        if(source == target)
            return true;
        
        for(int child : adj[source])
            if(!visited[child])
                ans = ans || dfs(child, target);

        return ans;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses, {});
        visited.assign(numCourses, false);
        vector<bool> answer;

        for(auto prerequisite : prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adj[u].push_back(v);
        }

        for(auto query : queries)
        {
            visited.assign(numCourses, false);
            int source = query[0];
            int target = query[1];
            answer.push_back(dfs(source, target));
        }

        return answer;
    }
};