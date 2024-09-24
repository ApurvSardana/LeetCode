class Solution {
public:

    bool isPrefixAndSuffix(string &str1, string &str2)
    {
        string prefix = "";
        string suffix = "";
        int len1 = str1.length();
        int len2 = str2.length();
        
        if(len2 < len1) return false;

        int i = 0; int j = len2 - len1;
        while(i < len2 && j < len2)
        {
            prefix += str2[i++];
            suffix += str2[j++];
        }

        if(prefix == suffix && prefix == str1) return true;

        return false;

    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int len = words.size();
        int count = 0;

        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};