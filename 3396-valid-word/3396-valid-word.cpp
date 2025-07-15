class Solution {
public:
    constexpr inline bool isDigit(char &ch){
        return (ch - '0' >= 0 && ch - '0' <= 9);
    }

    constexpr inline bool isAlphabet(char &ch){
        return (ch - 'a' >= 0 && ch - 'a' <= 25) || (ch - 'A' >= 0 && ch - 'A' <= 25);
    }

    constexpr inline bool isVowel(char &ch){
        set<char> st;
        st = {'a','e','i','o','u','A','E','I','O','U'};

        return st.find(ch) != st.end();
    }

    bool isValid(string word) {
        int vc = 0, cc = 0;

        for(char &ch : word){
            if(!isDigit(ch) && !isAlphabet(ch)) return false;

            if(isVowel(ch)) vc++;
            else if(isAlphabet(ch) && !isVowel(ch)) cc++;
        }

        return vc > 0 && cc > 0 && word.length() >= 3;
    }
};