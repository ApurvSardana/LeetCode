class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int> f(26, 0);
        for(char ch : s) f[ch-'a']++;

        set<int> evenF, oddF;
        for(int i = 0; i < 26; i++){
            if(f[i]&1) oddF.insert(f[i]);
            else if(f[i]!=0) evenF.insert(f[i]);
        }

        return *oddF.rbegin()-*evenF.begin();
    }
};