class Solution {
public:
    vector<double> answer;
    unordered_map<string, vector<pair<string, double>>> adj;

    void dijkstra(string &a, string &b)
    {
        unordered_map<string, double> distance;
        distance[a] = 1.0;

        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;

        pq.push({1.0, a});

        while(!pq.empty())
        {
            string node = pq.top().second;
            pq.pop();
            for(auto p : adj[node])
            {
                double ew = p.second;
                string adjacent = p.first;
                if(distance.find(adjacent) == distance.end() || distance[adjacent] > distance[node] * ew)
                {
                    distance[adjacent] = distance[node] * ew;
                    pq.push({distance[adjacent], adjacent});
                }
            }
        }
        if(distance.find(b) == distance.end())
            answer.push_back(-1.0);
        
        else answer.push_back(distance[b]);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        
        //Making the graph.
        for(int i = 0; i < n; i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1.0 / values[i]});
        }

        //Resolving each query using Dijkstra's for each.
        for(auto query : queries)
        {
            if(adj.find(query[0]) != adj.end() && adj.find(query[1]) != adj.end())
                dijkstra(query[0], query[1]);
            
            else
                answer.push_back(-1.0);
        }
        return answer;
    }
};