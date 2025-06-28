class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();

        vector<int> lps(m, 0);

        int i = 0, j = 1;
        while(j < m){
            if(needle[i] == needle[j]){
                i++;
                lps[j] = i;
                j++;
            }

            else if(i == 0){
                lps[j] = 0;
                j++;
            }

            else{
                i = lps[i-1];
            }
        }

        i = 0; j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                i++; j++;
                if(j == m){
                    return i-m;
                }
            }

            else if(j == 0){
                i++;
            }

            else{
                j = lps[j-1];
            }
        }

        return -1;
    }
};