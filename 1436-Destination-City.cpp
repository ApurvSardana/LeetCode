class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s;

        for(auto v : paths)
            s.insert(v[0]);
        
        for(auto v : paths)
            if(s.find(v[1]) == s.end())
                return v[1];
        
        return "";
    }
};