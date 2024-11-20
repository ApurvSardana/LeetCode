class Solution {
public:
    int takeCharacters(string s, int k) {
        int len = s.length();
        int ans = INT_MAX;

        vector<int> count(3, 0);

        for(auto ch : s)
        count[ch - 'a']++;

        if(*min_element(count.begin(), count.end()) < k)
        return -1;

        int l = 0;
        for(int r = 0; r < len; r++)
        {
            count[s[r] - 'a']--;

            while(*min_element(count.begin(), count.end()) < k)
            {
                count[s[l] - 'a']++;
                l++;
            }

            ans = min(ans, len - (r - l + 1));
        }
        return ans;
    }
};