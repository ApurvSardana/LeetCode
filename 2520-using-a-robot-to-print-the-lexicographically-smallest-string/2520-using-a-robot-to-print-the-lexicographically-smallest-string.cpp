class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        map<char, int> f;
        for(char ch : s) f[ch]++;

        string t = ""; string ans = "";
        for(int i = 0; i < n; i++){
            while(!t.empty() && t.back() <= (*f.begin()).first){
                ans += t.back();
                t.pop_back();
            }

            if(s[i] == (*f.begin()).first){
                ans += s[i];
                f[s[i]]--;
                if(f[s[i]] == 0) f.erase(s[i]);
            }

            else{
                t += s[i];
                f[s[i]]--;
                if(f[s[i]] == 0) f.erase(s[i]);
            }
        }
        reverse(t.begin(), t.end());
        return ans+t;
    }
};