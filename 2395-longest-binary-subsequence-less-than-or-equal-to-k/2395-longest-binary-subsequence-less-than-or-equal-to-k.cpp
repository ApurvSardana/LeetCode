class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int ans = 0;
        int pos = 0;

        int i = n-1; long long num = 0;

        while(i >= 0){
            if(s[i] == '0'){
                ans++;
                pos++;
            }

            else if(pos <= 30 && num + pow(2, pos) <= k){
                ans++;
                num += pow(2, pos);
                pos++;
            }

            i--;
        }


        return ans;
    }
};