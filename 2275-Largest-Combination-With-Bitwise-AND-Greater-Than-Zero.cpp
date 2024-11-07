class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        int max_combo;
        int i = 0;

        while(i <= 24)
        {
        max_combo = 0;
        for(int j = 0; j < candidates.size(); j++)
        if((candidates[j] >> i) & 1)
        max_combo++;
        
        ans = max(ans, max_combo);
        i++;
        }
        return ans;
    }
};