class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s = "";
        int index = 1;
        int i = 0;

        while(sentence[i] != '\0')
        {
        while(sentence[i] != ' ' && sentence[i] != '\0')
        {
            s += sentence[i];
            i++;

            if(s == searchWord)
            return index;
        }
        s = "";
        if(sentence[i] == '\0') return -1;
        index++;
        i++;
        }
        return -1;
    }
};