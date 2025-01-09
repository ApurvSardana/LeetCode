class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int ans = 0;

        for(auto s : words)
        {
            int i = 0;
            while(i <= n - 1)
            {
                if(s[i] != pref[i])
                    break;
                    i++;
            }
            
            if(i == n) ans++;
        }
        return ans;
    }
};