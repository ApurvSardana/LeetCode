class Solution {
public:
    unordered_map<char, string> m;
    void populate(vector<string> &ans, string &digits, string s, int index){
        if(index > digits.length() || s.length() == digits.length()){
            if(s != \\)
                ans.push_back(s);
            return;
        }

        for(int i = 0; i < m[digits[index]].length(); i++){
            populate(ans, digits, s+m[digits[index]][i], index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
       m['2'] = \abc\;
       m['3'] = \def\;
       m['4'] = \ghi\;
       m['5'] = \jkl\;
       m['6'] = \mno\;
       m['7'] = \pqrs\;
       m['8'] = \tuv\;
       m['9'] = \wxyz\;

       vector<string> ans;

       populate(ans, digits, \\, 0);

       return ans;
    }
};