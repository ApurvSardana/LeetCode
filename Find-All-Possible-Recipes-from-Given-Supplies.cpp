class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size(), m = supplies.size();
        vector<string> answer; set<string> available;
        vector<bool> visited(n, false);

        for(auto s : supplies)
            available.insert(s);

        for(int i = 0; i < n; i++){
            int init_size = available.size();
            for(int i = 0; i < n; i++){
                if(visited[i])
                    continue;
                string recipe = recipes[i];
                bool flag = true;
                for(auto ingredient : ingredients[i]){
                    if(available.find(ingredient) == available.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    available.insert(recipe);
                    answer.push_back(recipe);
                    visited[i] = true;
                }
            }
            if(available.size() == init_size)
                break;
        }
        return answer;
    }
};