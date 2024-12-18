class Solution {
public:
    int find(int x, vector<int> &parent)
    {
        if(parent[x] >= 0)
            return parent[x] = find(parent[x], parent);
        return x;
    }
    bool union_(int a, int b, vector<int> &parent)
    {
        a = find(a, parent);
        b = find(b, parent);

        if(a == b)
            return false;
        
        if(parent[a] < parent[b])
            parent[b] = a;
        
        else if(parent[b] < parent[a])
            parent[a] = b;
        
        else
        {
            parent[b] = a;
            parent[a]--;
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        vector<pair<int, pair<int, int>>> edges;
        vector<int> parent(points.size(), -1);

        for(int i = 0; i < points.size(); i++)
            for(int j = i+1; j < points.size(); j++)
            {
                int weight = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                edges.push_back(make_pair(weight, make_pair(i, j)));
            }
        
        //Kruskal's Algorithm
        sort(edges.begin(), edges.end());

        for(auto edge : edges)
            if(union_(edge.second.second, edge.second.first, parent))
                ans += edge.first;

        return ans;
    }
};