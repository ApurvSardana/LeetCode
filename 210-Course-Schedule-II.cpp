class Solution {
public:
    bool flag = false;
    void dfs(int s, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order, vector<bool> &beenThere)
    {
        beenThere[s] = true;

        for(int i : adj[s])
        {
            if(beenThere[i] == true && visited[i] == false)
            {
                flag = true;
                return;
            }

            if(!visited[i])
                dfs(i, adj, visited, order, beenThere);
        }

        visited[s] = true;
        order.push_back(s);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<bool> visited(numCourses, false);
        vector<bool> beenThere(numCourses, false);
        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites)
            adj[p[0]].push_back(p[1]);
        
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == true)
                continue;
            
            else
                dfs(i, adj, visited, order, beenThere);

            if(flag == true)
                return {};
        }
        return order;
    }
};