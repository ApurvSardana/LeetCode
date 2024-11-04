class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 0;
        int i = 0;
        int length = word.length();
        
        string c = "";
        while(i < length)
        {
            c[0] = word[i];
            if(count > 0 && count < 9)
            {
                if(c[0] == word[i - 1])
                count++;

                else
                {
                comp += to_string(count);
                comp += word[i - 1];
                count = 1;
                }
            }

            else if(count == 0)
            count = 1;

            else
            {
                comp += '9';
                comp += word[i - 1];
                count = 1;
            }
            i++;
        }
        comp += to_string(count);
        comp += c[0];

        return comp;
    }
};