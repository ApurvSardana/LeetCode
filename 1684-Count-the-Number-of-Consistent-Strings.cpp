class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        int count = 0;
        for(char i : allowed)
        {
            s.insert(i);
        }
        for(string str : words)
        {
            int flag = 1;
            for(char ch : str)
            {
                if(s.find(ch) == s.end())
                flag = 0;
            }
            if(flag == 1)
            count++;
        }
        return count;
    }
};