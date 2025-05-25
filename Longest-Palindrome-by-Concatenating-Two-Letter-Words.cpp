class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> f;
        int ans = 0;
        for(auto s : words)
            f[s]++;
        
        bool oddPalin = false;

        for(auto p : f){
            //cout << p.first << " : " << p.second << endl;
            string s = p.first;
            if(s[0] != s[1]){
                string temp(s.rbegin(), s.rend());
                ans += min(f[s], f[temp]);
            }

            else if(f[s]&1){
                oddPalin = true;
                ans += (f[s]-1);
            }

            else{
                ans += (f[s]);
            }
        }

        return (oddPalin) ? 2*ans+2 : 2*ans;
    }
};