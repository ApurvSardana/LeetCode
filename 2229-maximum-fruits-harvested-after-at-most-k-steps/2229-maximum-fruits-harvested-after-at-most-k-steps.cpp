class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> profit(200020, 0);

        for(auto fruit : fruits){
            profit[fruit[0]] = fruit[1];
        }

        vector<int> left(200020, 0), right(200020, 0);

        left[0] = right[0] = profit[startPos];

        for(int i = startPos-1; i >= 0; i--){
            left[startPos-i] = left[startPos-i-1] + profit[i];
        }

        for(int i = startPos+1; i < 200020; i++){
            left[i] = left[i-1];
        }

        for(int i = startPos+1; i < 200020; i++){
            right[i-startPos] = right[i-startPos-1] + profit[i];
        }

        int ans = INT_MIN;
        for(int steps = 0; steps <= k; steps++){
            ans = max(ans, left[steps]);
            ans = max(ans, right[steps]);
            if(k-2*steps >= 0){
                ans = max(ans, left[steps]+right[k-2*steps]-profit[startPos]);
                ans = max(ans, right[steps]+left[k-2*steps]-profit[startPos]);
            }
        }

        return ans;
    }
};