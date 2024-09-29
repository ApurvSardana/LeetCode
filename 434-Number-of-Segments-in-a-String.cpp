class Solution {
public:
    int countSegments(string s) {

        if(s.length() == 0) return 0;
        
        int count = 0;
        int i = 0;
        while(s[i] != '\\0')
        {
            bool empty = true;

            while(s[i] != '\\0' && s[i] != ' ')
            {
                empty = false;
                i++;
            }

            if(!empty) count++;

            if(s[i] != '\\0') i++;
        }

        return count;
    }
};