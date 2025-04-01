class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp;
        dp.assign(n, 0);

        //dp[i] represents when you are at position i, the max amount you can get from position i;
        dp[n-1] = questions[n-1][0];

        for(int i = n-2; i >= 0; i--){
            if(i+questions[i][1] >= n-1)
                dp[i] = max((long long)questions[i][0], dp[i+1]);
            
            else
                dp[i] = max(questions[i][0]+dp[i+questions[i][1]+1], dp[i+1]);
        }

        return dp[0];

    }
};