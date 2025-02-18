class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();

        string ans = "";
        for(int i = 1; i <= n+1; i++){
            ans += to_string(i);
        }

        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            if(pattern[i] == 'D'){
                l = i;
                while(i < n && pattern[i] != 'I')
                    i++;
                
                r = i;
                reverse(ans.begin()+l, ans.begin()+r+1);
            }
        }
        return ans;
    }
};