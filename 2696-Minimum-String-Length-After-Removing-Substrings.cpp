class Solution {
public:
    int minLength(string s) {
        int len = s.length();
        for(int i = 0; i < len - 1; i++)
        {
            string str = "";
            str += s[i];
            str += s[i+1];
            if(str == "AB" || str == "CD")
            {
                s.erase(i, 2);
                if(i >= 1) i -= 2;

                if(i == 0) i -= 1;
            }
            len = s.length();
        }

        return s.length();
        
    }
};