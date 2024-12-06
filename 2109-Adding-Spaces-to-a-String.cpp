class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        unordered_map <int, int> m;

        for(int i : spaces)
            m[i] = i;
        
        int i = 0;

        while(i < s.length())
        {
            if(m.find(i) != m.end())
                ans += ' ';
            
            ans += s[i];
            i++;
        }
        return ans;
    }
};