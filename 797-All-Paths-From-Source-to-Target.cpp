class Solution {
public:
    vector<vector<int>> paths;
    vector<int> path;
    void dfs(int source, int target, vector<vector<int>> &graph)
    {
        path.push_back(source);

        if(source == target)
        {
            paths.push_back(path);
            path.pop_back();
            return;
        }

        for(int child : graph[source])
            dfs(child, target, graph);
            
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dfs(0, n - 1, graph);
        return paths;
    }
};