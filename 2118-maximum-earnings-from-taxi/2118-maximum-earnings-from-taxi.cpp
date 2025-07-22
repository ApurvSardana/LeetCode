class Solution {
public:
    int bs(vector<vector<int>> &rides, int l, int r, int limit){
        while(l <= r){
            int mid = l + (r-l)/2;

            int end = rides[mid][1];
            if(end <= limit) l = mid+1;
            else r = mid-1;
        }

        return l-1;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int passengers = rides.size();

        sort(rides.begin(), rides.end(), [&](vector<int> &a, vector<int> &b){return a[1] < b[1];});

        vector<long long> dp(passengers, 0LL);

        dp[0] = (rides[0][1]-rides[0][0]+rides[0][2]);
        for(int i = 1; i < passengers; i++){
            long long start = rides[i][0];
            long long end = rides[i][1];
            long long tip = rides[i][2];
            int prev = bs(rides, 0, i-1, start);

            if(prev <= -1) dp[i] = max(dp[i-1], end-start+tip);
            else dp[i] = max(dp[i-1], dp[prev]+end-start+tip);
        }
        
        return dp[passengers-1];
    }
};