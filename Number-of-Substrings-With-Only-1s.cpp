class Solution {
public:
    int MOD = 1e9 + 7;
    using ll = long long;
    int numSub(string s) {
        ll n = s.length();
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            if(s[i] == '1'){
                ll j = i+1;
                while(j < n && s[j] == '1'){
                    j++;
                }

                ll len = j-i;
                ans = (ans + ((len*(len-1))/2) + len)%MOD;
                i = j;
            }
        }

        return ans;
    }
};