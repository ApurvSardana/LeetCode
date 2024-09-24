class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string str = s1 + " " + s2 + " ";
        map<string, int> m;
        vector<string> ans;
        for(int i = 0; i < str.length(); i++)
        {
            string word = "";
            while(str[i] != ' ')
            {
                word += str[i];
                i++;
            }
            if(m.find(word) != m.end())
            m[word]++;

            else
            m[word] = 1;
        }

        for(auto n : m)
        {
            if(n.second == 1) 
            ans.push_back(n.first);
        }

        return ans;
    }
};