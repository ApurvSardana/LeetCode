class Solution {
public:
string ands(string &s1, string &s2)
{
    string ans = \\;
    for(int i = 0; i < max(s1.length(), s2.length()); i++)
    {
        if(s1[i] == s2[i])
        ans += s1[i];

        else break;
    }
    return ans;
}
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            ans = ands(ans, strs[i]);
        }
        return ans;
    }
};