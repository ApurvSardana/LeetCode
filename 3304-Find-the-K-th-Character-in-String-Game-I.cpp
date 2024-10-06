class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k)
        {
            string app = "";
            for(int i = 0; i < word.length(); i++)
            {
                if(word[i] == 'z')
                app += 'a';

                else
                app += (char)(word[i] + 1);
            }
            word += app;
        }
        return word[k-1];
    }
};