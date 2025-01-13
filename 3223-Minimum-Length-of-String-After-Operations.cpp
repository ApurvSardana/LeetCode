class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();

        unordered_map <char, int> m;

        for(char c : s)
            m[c]++;
        
        for(auto p : m)
        {
            char c = p.first;
            int count = p.second;

            while(count > 2)
            {
                count -= 2;
                len -= 2;
            }
        }
        return len;
    }
};