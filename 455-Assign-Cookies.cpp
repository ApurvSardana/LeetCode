class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int gSize = g.size();
        int sSize = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; int j = 0;
        while(i < gSize && j < sSize)
        {
            if(g[i] <= s[j])
            {
                ans++;
                i++;
            }

            j++;
        }
        return ans;
    }
};