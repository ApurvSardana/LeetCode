class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knowTime(n, INT_MAX);

        knowTime[0] = 0;
        knowTime[firstPerson] = 0;

        vector<vector<pair<int, int>>> adj(n);

        for(auto &edge : meetings)
        {
            int u = edge[0];
            int v = edge[1];
            int ew = edge[2];

            adj[u].push_back(make_pair(v, ew));
            adj[v].push_back(make_pair(u, ew));
        }

        queue<pair<int, int>> q;

        q.push({0, 0});
        q.push({firstPerson, 0});

        while(!q.empty())
        {
            auto [node, t] = q.front();
            q.pop();

            for(auto p : adj[node])
            {
                auto [adjacent, time] = p;
                if(time >= t && knowTime[adjacent] > time)
                {
                    knowTime[adjacent] = time;
                    q.push({adjacent, time});
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(knowTime[i] != INT_MAX)
                ans.push_back(i);
                
        return ans;
    }
};