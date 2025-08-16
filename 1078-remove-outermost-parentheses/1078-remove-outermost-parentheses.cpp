class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string ans = "";
        vector<int> balance(n, 1);

        for(int i = 1; i < n; i++){
            balance[i] = balance[i-1] + int((s[i] == '(') ? +1 : -1);
        }

        vector<int> next_smaller(n, -1);
        stack<int> st;
        st.push(n-1);

        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && balance[st.top()] >= balance[i])
                st.pop();
            
            if(!st.empty())
                next_smaller[i] = st.top();
            
            st.push(i);
        }

        // for(int b : balance)
        //     cout << b << ", ";

        // cout << endl;

        // for (int ns : next_smaller)
        //     cout << ns << ", ";
        for(int i = 0; i < n; i++){
            if(balance[i] == 1){
                ans += s.substr(i+1, next_smaller[i]-i-1);
                i = next_smaller[i];
            }

            if(i < 0)
                break;
        }

        return ans;
    }
};