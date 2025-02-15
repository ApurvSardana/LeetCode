class Solution {
public:
    bool sub(const string &s, const string &p){
        int n = s.length();
        int m = p.length();

        int i = 0, j = 0;

        while(i < n && j < m){
            if(s[i] == p[j]){
                i++;
                j++;
            }

            else
                i++;
        }

        if(j < m)
            return false;
        
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map <string, int> m;
        for(auto word : words)
            m[word]++;
        
        for(auto w : m)
            if(sub(s, w.first))
                count += w.second;
        
        return count;
    }
};