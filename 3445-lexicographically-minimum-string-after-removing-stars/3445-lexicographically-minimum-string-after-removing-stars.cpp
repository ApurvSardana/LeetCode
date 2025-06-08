class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<stack<int>> v(26);

        for(int i = 0; i < n; i++){
            if(s[i] != '*'){
                v[s[i]-'a'].push(i);
            }

            else{
                for(int i = 0; i < 26; i++){
                    if(!v[i].empty()){
                        s[v[i].top()] = '*';
                        v[i].pop();
                        break;
                    }
                }
            }
        }

        string ans = "";
        for(char ch : s)
            if(ch != '*') ans += ch;

        return ans;
    }
};