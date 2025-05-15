class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans; int n = groups.size();

        int i = 1; ans.push_back(words[0]);
        int val = groups[0];
        while(i < n){
            if(groups[i] != val){
                ans.push_back(words[i]);
                val = val^1;
            }
            i++;
        }
        return ans;
    }
};