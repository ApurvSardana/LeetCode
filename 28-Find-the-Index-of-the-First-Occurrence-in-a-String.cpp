class Solution {
public:
    int strStr(string haystack, string needle) {
        int Totalen = haystack.length();
        
        int len = needle.length();
        
        for(int i = 0; i < Totalen - len + 1; i++)
        {
            string str = \\;
            for(int j = i; j < i + len; j++)
            {
                str += haystack[j];
            }
            if(str == needle) 
            return i;
            
        }
        return -1;
    }
};