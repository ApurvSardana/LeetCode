class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;

        string ans = \\;
        for(int i = 0; i < s.length() - 1; i++)
        {
            string str = \\;

            int l = i, r = i;
            while(l >= 0 && r < s.length())
            {
                if(s[l] == s[r])
                {
                    if(str == \\)
                    str += s[l];

                    else
                    str = s[l] + str + s[r];

                    l--;
                    r++;

                }
                else
                break;
            }
            if(str.length() > ans.length())
                    ans = str;

            l = i; r = i+1;
            str = \\;
            while(l >= 0 && r < s.length())
            {
                if(s[l] == s[r])
                {
                    str = s[l] + str + s[r];
                    l--;
                    r++;
                }

                else
                break;

            }
            if(str.length() > ans.length())
                    ans = str;
        }

        return ans;
    }
};