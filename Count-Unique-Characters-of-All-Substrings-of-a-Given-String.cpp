1class Solution {
2public:
3    int uniqueLetterString(string s) {
4        int n = s.length();
5        vector<vector<int>> at(26, vector<int>{-1});
6        vector<int> dp(n, 0);
7
8        for(int i = 0; i < n; i++){
9            at[s[i]-'A'].push_back(i);
10            for(int ch = 0; ch < 26; ch++){
11                int sz = at[ch].size();
12                if(sz == 1) continue;
13                dp[i] += (at[ch][sz-1] - at[ch][sz-2]);
14            }
15        }
16
17        return accumulate(dp.begin(), dp.end(), 0);
18    }
19};