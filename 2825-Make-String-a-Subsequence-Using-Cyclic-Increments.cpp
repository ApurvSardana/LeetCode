class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        if(len1 < len2)
            return false;
        
        int i = 0;
        int j = 0;

        while(i < len1 && j < len2)
        {
            int ch1 = (str1[i] - 'a');
            int ch2 = (str2[j] - 'a');

            if(ch1 == ch2 || ch1 == ch2 - 1 || (ch2 == 0 && ch1 == 25))
            {
                i++;
                j++;
            }

            else
                i++;
        }

        if(j == len2)
            return true;
        
        return false;
    }
};