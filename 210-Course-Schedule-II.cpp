class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
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
            return {};
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visited[node] = true;

            order.push_back(node);

            for(int i : adj[node])
            {
                inDegree[i]--;
                if(inDegree[i] == 0)
                    q.push(i);
            }
        }

        for(int i = 0; i < numCourses; i++)
            if(!visited[i])
                return {};

        reverse(order.begin(), order.end());
        
        return order;
    }
};