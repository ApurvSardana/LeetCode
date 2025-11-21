class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> occ(26, {-1, -1});

        for(int i = 0; i < n; i++){
            if(occ[s[i]-'a'].first == -1) occ[s[i]-'a'].first = i;
            else occ[s[i]-'a'].second = i;
        }

        vector<vector<bool>> vis(26, vector<bool> (26, 0));
        int count = 0;
        for(int i = 1; i < n-1; i++){
            for(int j = 0; j < 26; j++){
                if(occ[j].first == -1 || occ[j].second == -1) continue;
                if(occ[j].first < i && occ[j].second > i){
                    int m = s[i]-'a';
                    if(!vis[m][j]){
                        vis[m][j] = true;
                        count++;
                    }
                }
            }
        }

        // for(auto str : st) cout << str << endl;
        return count;

    }
};