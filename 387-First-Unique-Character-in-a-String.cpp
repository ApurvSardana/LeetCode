class Solution {
public:
    int firstUniqChar(string s) {
        queue<pair<char, int>> q;
        unordered_map<char, int> m;
        int len = s.length();

        for(int i = 0; i < len; i++)
        {
            if(m.find(s[i]) == m.end())
            {
                q.push({s[i], i});
                m[s[i]] = 1;
            }

            else
            m[s[i]]++;
        }

        while(!q.empty())
        {
            if(m[q.front().first] == 1)
            return q.front().second;

            q.pop();
        }

        return -1;
    }
};