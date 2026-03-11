1class Solution {
2public:
3    set<string> st;
4    vector<int> dp;
5    bool f(string &s, int first, int curr){
6        if(curr >= s.length()) return false;
7        if(curr == s.length()-1 and st.count(s.substr(first, curr-first+1))){
8            dp[first] = 1;
9            return true;
10        }
11
12        if(dp[first] != -1) return dp[first];
13        dp[first] = f(s,first,curr+1);
14        if(st.count(s.substr(first, curr-first+1))) dp[first] |= f(s,curr+1,curr+1);
15        return dp[first];
16    }
17    bool wordBreak(string s, vector<string>& wordDict) {
18        st = set<string>(wordDict.begin(), wordDict.end());
19        dp.assign(s.length(),-1);
20        return f(s,0,0);
21    }
22};