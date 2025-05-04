class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i = 0; i < dominoes.size(); i++){
            sort(dominoes[i].begin(), dominoes[i].end());
        }

        map<vector<int>, int> freq;

        for(auto v : dominoes){
            freq[v]++;
        }
        int ans = 0;
        for(auto p : freq){
            ans += (p.second*(p.second-1))/2;
        }
        return ans;
    }
};