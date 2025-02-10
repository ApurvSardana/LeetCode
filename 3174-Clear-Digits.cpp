class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<char> st;

        for(int i = 0; i < n; i++){
            if(s[i] >= 48 && s[i] <= 57 && !st.empty()){
                st.pop();
            }

            else if(s[i] >= 97 && s[i] <= 122)
                st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};