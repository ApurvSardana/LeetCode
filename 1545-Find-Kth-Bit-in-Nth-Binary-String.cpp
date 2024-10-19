class Solution {
public:
    string reverses(string s)
    {
        long long i = s.length() - 1;
        string ans = "";
        for(; i >= 0; i--)
        {
            ans += s[i];
        }
        return ans;
    }
    string inverts(string s)
    {
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '0')
            s[i] = '1';

            else 
            s[i] = '0';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        if(n == 1 || k == 1)
        return '0';

        unordered_map <int, string> S;
        S[1] = "0";

        for(int i = 2; i <= 20; i++)
        {
            S[i] = S[i - 1] + '1' + reverses(inverts(S[i - 1]));
        }

        return S[n][k-1];
    }
};