class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();
        vector<int> f(26, 0);

        for(int i = 0; i < n; i++){
            f[s[i]-'a']++;
        }

        int maxv = 0; int maxc = 0;

        for(int i = 0; i < 26; i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                maxv = max(maxv, f[i]);
            }

            else
                maxc = max(maxc, f[i]);
        }

        return maxv+maxc;
    }
};