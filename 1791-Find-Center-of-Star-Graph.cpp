class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> count(n+1, 0);

        for(auto edge : edges)
        {
            count[edge[0]]++;
            count[edge[1]]++;
        }

        for(int i = 1; i <= n; i++)
            if(count[i] == n - 1)
                return i;

                return -1;
    }
};