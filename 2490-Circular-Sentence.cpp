class Solution {
public:
    bool isCircularSentence(string sentence) {
        int size = sentence.length();

        if(sentence[0] != sentence[size - 1])
        return false;

        char ch = ' ';

        int i = 0;
        while(i < size)
        {
        while( i < size && sentence[i] != ' ')
        ch = sentence[i++];

        if(i < size - 1 && sentence[i+1] != ch)
        return false;

        i++;
        }

    return true;
    }
};