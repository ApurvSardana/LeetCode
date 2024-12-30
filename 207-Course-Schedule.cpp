class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<bool> visited(numCourses, false);
       vector<int> inDegree(numCourses, 0);

       vector<vector<int>> adj(numCourses);

       for(auto node : prerequisites)
       {
            adj[node[0]].push_back(node[1]);
            inDegree[node[1]]++;
       }
        
        queue<int> q;

        for(int i = 0; i < numCourses; i++)
            if(!visited[i] && inDegree[i] == 0)
                q.push(i);

        if(q.empty())
            return false;
        
        while(!q.empty())
        {
            int node = q.front();
            visited[node] = true;
            q.pop();
        
            for(int i : adj[node])
            {
                inDegree[i]--;

                if(inDegree[i] == 0)
                    q.push(i);
            }
        }

        for(int i = 0; i < numCourses; i++)
            if(visited[i] == false)
                return false;

        return true;
    }
};