class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> arr(s.length(), 0);
        stack<pair<char, int>> st;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            st.push({s[i], i});

            else if(!st.empty() && s[i] == ')')
            {
                
                arr[st.top().second] = 1;
                arr[i] = 1;
                st.pop();
            }

        }

        for(int i = 0; i < arr.size(); i++)
        {
            int count = 0;
            while(i < arr.size() && arr[i] == 1)
            {
                count++;
                i++;
            }
            if(count > ans) ans = count;
        }

        return ans;
    }
};