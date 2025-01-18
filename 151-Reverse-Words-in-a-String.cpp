class Solution {
public:
    string reverseWords(string s) {
        s = " " + s;

        int n = s.length();
        string word = "";
        string answer = "";

        int i = n - 1;

        while(i >= 0)
        {
            if(s[i] == ' ' && word == "")
                i--;
            
            else if(s[i] == ' ')
            {
                answer += word + " ";
                word = "";
                i--;
            }

            else
            {
                word = s[i] + word;
                i--;
            }
        }
        return answer.substr(0, answer.length() - 1);
    }
};