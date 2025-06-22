class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;

        int i = 0; string temp = "";
        while(i < n){
            while(i < n && temp.length() < k){
                temp += s[i++];
            }

            while(temp.length() < k) temp += fill;

            if(temp.length() == k){ans.push_back(temp); temp = "";}
        }

        return ans;
    }
};