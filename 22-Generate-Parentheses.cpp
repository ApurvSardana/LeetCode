class Solution {
public:
    vector<string> ans;
    bool checkValid(string &s){
        stack<char> st;

        for(char ch: s){
            if(ch == '(')
                st.push(ch);
            
            else if(ch == ')' && st.empty())
                return false;
            
            else
                st.pop();
        }

        return st.empty();
    }
    void f(string &s, int len){
        if(s.length() == len){
            if(checkValid(s))
                ans.push_back(s);
            return;
        }

        else if(s.length() == 0){
            string s3 = s+\(\;
            f(s3, len);
        }

        else{
            string s1 = s + '(';
            f(s1, len);

            string s2 = s + ')';
            f(s2, len);
        }
    }
    vector<string> generateParenthesis(int n) {
        string combo = \\;

        f(combo, 2*n);

        return ans;
    }
};