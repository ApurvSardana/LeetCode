class Solution {
public:
    vector<vector<string>> ans;

    bool valid(vector<string> &v, int l){
        int len = 0;
        for(auto s : v) len += s.length();
        if(len != l) return false;

        for(auto s : v){
            int i = 0; int j = s.length()-1;
            while(i < j){
                if(s[i] == s[j]){
                    i++; j--;
                }

                else return false;
            }
        }

        return true;

    }
    void f(string s, vector<string> &curr, int index, int length){
        if(index > s.length()) return;

        if(valid(curr, s.length())){
            ans.push_back(curr);
        }

        if(index == s.length()) return;
        for(int i = index; i < s.length(); i++){
            if(i+length-1 >= s.length() || (i > index && s[i] == s[i-1])) continue;

            curr.push_back(s.substr(i, length));
            for(int l = 1; l <= s.length(); l++){
                if(i+length+l-1 <= s.length()) f(s, curr, i+length, l);
            }
            curr.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> curr;
        for(int length = 1; length <= n; length++){
            f(s, curr, 0, length);
        }

        return ans;
    }
};