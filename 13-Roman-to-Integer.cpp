class Solution {
public:
    int ans;
    unordered_map<char, int> m;
    int roman(string &s, int i)
    {
        if(i < 0)
            return ans;
            
        if(i == s.length() - 1)
            return ans = m[s[i]] + roman(s, i - 1);

        else if(m[s[i+1]] > m[s[i]])
            return ans = roman(s, i - 1) - m[s[i]];
        
        else if(i != 0)
            return ans = m[s[i]] + roman(s, i - 1);

        else
            return ans + m[s[i]];
    }

    int romanToInt(string s) {
        int n = s.length(), ans = 0;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        ans = roman(s, n - 1);
        
        return ans;
    }
};