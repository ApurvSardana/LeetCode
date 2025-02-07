class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map <int, int> color_frequency;
        unordered_map <int, int> color;

        vector<int> ans;
        for(auto query : queries){
            int ball = query[0];
            int c = query[1];

            if(color.find(ball) != color.end()){
                color_frequency[color[ball]]--;
                if(color_frequency[color[ball]] == 0)
                    color_frequency.erase(color[ball]);
            }
            
            color_frequency[c]++;
            color[ball] = c;
            ans.push_back(color_frequency.size());
        }
        
        return ans;
    }
};