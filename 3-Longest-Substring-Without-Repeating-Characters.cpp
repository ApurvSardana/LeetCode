class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int ans = 0;
         for(int i = 0; i < s.length(); i++)
         {
            int curr_len = 0;
            set<char> st;
            for(int j = i; j < s.length(); j++)
            {
                if(st.find(s[j]) != st.end())
                {
                break;
                }

                st.insert(s[j]);
                curr_len++;
                ans = max(ans, curr_len);
            }
         }
         return ans;
    }
};