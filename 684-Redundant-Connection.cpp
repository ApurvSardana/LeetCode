class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] > 0)
            return parent[x] = find(parent[x], parent);
        
        return x;
    }
    bool unions(int a, int b, vector<int> &parent){
        a = find(a, parent);
        b = find(b, parent);

        if(a == b)
            return false;
        
        if(parent[a] < parent[b])
            parent[b] = a;
        
        else if(parent[b] < parent[a])
            parent[a] = b;
        
        else{
            parent[b] = a;
            parent[a]--;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, -1);

        for(auto edge : edges)
            if(!unions(edge[0], edge[1], parent))
                return edge;
        return {};
    }
};