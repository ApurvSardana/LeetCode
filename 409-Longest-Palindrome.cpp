class Solution {
public:
    int longestPalindrome(string s) {
        int length = 0;
        int max_odd = 0;
        map<char, int> m;

        bool flag = false;

        for(auto ch : s)
        m[ch]++;

        for(auto ch : m)
        {
        if(ch.second % 2 == 0)
        length += ch.second;

        else
        {
            flag = true;
            length += (ch.second - 1);
        }
        }

        return (flag == true) ? length + 1 : length;
    }
};