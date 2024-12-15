class Solution {
public:
    int find(int x, vector<int> &parent)
    {
        if(parent[x] > 0)
            return parent[x] = find(parent[x], parent);
        
        return x;
    }

    void unions(int a, int b, vector<int> &parent)
    {
        a = find(a, parent);
        b = find(b, parent);

        if(a == b)
            return;
        
        else if(parent[a] < parent[b])
            parent[b] = a;
        
        else if(parent[b] < parent[a])
            parent[a] = b;

        else
        {
            parent[b] = a;
            parent[a]--;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();

        vector<int> parent(nodes + 1, -1);

        for(int i = 0; i < nodes; i++)
            for(int j = i + 1; j < nodes; j++)
                if((isConnected[i][j] == 1))
                    unions(i + 1, j + 1, parent);
        
        int provinces = 0;
        for(int i = 1; i < nodes + 1; i++)
            if(parent[i] < 0)
                provinces++;
        
        return provinces;
    }
};