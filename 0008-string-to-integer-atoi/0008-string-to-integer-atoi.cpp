class Solution {
public:
    constexpr inline bool isLetter(char &ch){
        int small = ch-'a', big = ch-'A';

        return (small >= 0 && small < 26) || (big >= 0 && big < 26);
    }

    constexpr inline bool isSpecial(char &ch){
        return (ch == ' ' || ch == '.');
    }

    constexpr inline bool isSign(char &ch){
        return (ch == '+' || ch == '-');
    }

    int myAtoi(string s) {
        int len = s.length();
        long long ans = 0;
        int i = 0;
        while(i < len && s[i] == ' '){
            i++;
        }

        if(i == len) return 0;
        if(isLetter(s[i]) || isSpecial(s[i])) return 0;

        bool isNegative = (s[i] == '-');

        if(isSign(s[i])) i++;

        while(i < len){
            if(isLetter(s[i]) || isSpecial(s[i]) || isSign(s[i])) break;

            int digit = s[i]-'0';

            ans = (ans*10 + digit);
            if(!isNegative && ans >= INT_MAX) return INT_MAX;
            if(isNegative && -ans <= INT_MIN) return INT_MIN;

            i++;
        }

        return (isNegative) ? -ans : ans;
    }
};