class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n = graph.size();
        vector<vector<int>> rev_graph(n);
        vector<int> outdegree(n, 0), safe;

        for(int i = 0; i < n; i++){
            outdegree[i] = graph[i].size();
            for(int j : graph[i])
                rev_graph[j].push_back(i);
        }

        queue<int> q;

        for(int i = 0; i < n; i++)
            if(outdegree[i] == 0)
                q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int adjacent : rev_graph[node]){
                outdegree[adjacent]--;
                if(outdegree[adjacent] == 0)
                    q.push(adjacent);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};