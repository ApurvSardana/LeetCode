class Solution {
public:
    bool findHD(string &a, string &b){
        if(a.length() != b.length()) return false;

        int diff = 0;
        for(int i = 0; i < a.length(); i++)
            if(a[i] != b[i])
                diff++;
            
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& group) {
        int n = words.size();
        vector<vector<bool>> ham(n, vector<bool> (n, false));

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ham[i][j] = findHD(words[i], words[j]);
            }
        }

        //dp[i] represents the longest subsequence uptill index i;
        vector<int> dp(n, 1);

        for(int j = 1; j < n; j++){
            for(int i = 0; i < j; i++){
                if(ham[i][j] && group[i] != group[j]){
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }

        // for(int i = 0; i < n; i++) 
        //     cout << i << " : " << dp[i] << endl;
        int index = 0; int max_len = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] > max_len){
                index = i;
                max_len = dp[i];
            }
        }

        //cout << max_len << endl;
        vector<string> ans; ans.push_back(words[index]);
        int curr = index;
        for(int i = index-1; i >= 0; i--){
            if(ans.size() == max_len) break;
            if(ham[i][curr] && group[i] != group[curr] && dp[i] == dp[curr]-1){
                ans.push_back(words[i]);
                curr = i;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};