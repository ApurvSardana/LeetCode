class Solution {
public:
    class comp{
        public:
        bool operator()(pair<string, int> &a, pair<string, int> &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> f;

        for(int i = 0; i < n; i++)
            f[words[i]]++;
        
        vector<pair<string, int>> v(f.begin(), f.end());
        sort(v.begin(), v.end(), comp());

        // for(auto it : v){
        //     cout << it.first << " : " << it.second << endl;
        // }

        vector<string> ans;
        auto it = v.begin();
        for(int i = 0; i < k; i++){
            ans.push_back(it->first);
            it++;
        }
        
        return ans;
    }
};