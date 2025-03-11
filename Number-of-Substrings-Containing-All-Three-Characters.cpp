class Solution {
public:
    bool f(vector<int> &count){
        return count[0] && count[1] && count[2];
    }
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> count(3, 0);
        int ans = 0;
        int start = 0;
        int end = 0;

        while(end < n){
            count[s[end] - 'a']++;
            
            while(f(count)){
                ans += n - end;
                count[s[start] - 'a']--;
                start++;
            }
            end++;
        }
        return ans;
    }
};