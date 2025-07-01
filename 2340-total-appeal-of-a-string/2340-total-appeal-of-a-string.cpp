class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        unordered_set<char> st;
        vector<int> de(n, 0);
        vector<vector<int>> index(26, vector<int> {});

        vector<long long> dp(n, 0);

        for(int i = 0; i < n; i++){
            st.insert(s[i]);
            de[i] = st.size();
        }

        dp[0] = 1;
        index[s[0]-'a'].push_back(0);
        for(int i = 1; i < n; i++){
            if(de[i] != de[i-1]){
                dp[i] = dp[i-1] + i + 1;
            }

            else{
                int k = index[s[i]-'a'].back();
                dp[i] = dp[i-1] + i - k;
            }

            index[s[i]-'a'].push_back(i);
        }

        return accumulate(dp.begin(), dp.end(), 0LL);
    }
};