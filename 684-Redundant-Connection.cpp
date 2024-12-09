class Solution {
public:
    int arr[1001];

    Solution() {
    fill(begin(arr), end(arr), -1);
}

    int find(int x)
    {
        if(arr[x] >= 0)
            return arr[x] = find(arr[x]);
        return x;
    }

    bool unions(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if(pa == pb)
            return false;
        
        int ra = -arr[pa];
        int rb = -arr[pb];

        if(ra > rb)
            arr[pb] = pa;
        
        else if(rb > ra)
            arr[pa] = pb;
        
        else
        {
            arr[pa] = pb;
            arr[pb] -= 1;
        }

        return true;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;

        for(auto p : edges)
        {
            if(unions(p[0], p[1]) == false)
                ans = p;
        }
        return ans;
    }
};