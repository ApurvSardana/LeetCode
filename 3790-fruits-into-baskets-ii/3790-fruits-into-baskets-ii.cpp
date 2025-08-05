class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++){
            bool placed = false;
            for(int j = 0; j < n; j++){
                if(!vis[j] && baskets[j] >= fruits[i]){
                    vis[j] = true;
                    placed = true;
                    break;
                }
            }

            if(!placed) ans++;
        }

        return ans;
    }
};