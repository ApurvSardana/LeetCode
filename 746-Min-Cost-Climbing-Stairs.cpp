class Solution {
public:
    vector<int> dp;

    int helper(vector<int> &cost, int i){
        if(i == 0 || i == 1)
            return dp[i] = 0;
        
        else if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = min(helper(cost, i-1) + cost[i-1], helper(cost, i-2) + cost[i-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //dp[i] stores the min cost to reach the ith step
        dp.assign(n+1, -1);
        return helper(cost, n);
    }
};