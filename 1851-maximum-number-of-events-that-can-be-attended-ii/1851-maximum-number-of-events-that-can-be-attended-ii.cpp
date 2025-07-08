class Solution {
public:
    class comp{
        public:
        bool operator()(vector<int> &a, vector<int> &b){
            if(a[1] == b[1]){
                if(a[2] == b[2]){
                    return a[0] >= b[0]; 
                }
                return a[2] >= b[2];
            }

            return a[1] < b[1];
        }
    };

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        sort(events.begin(), events.end(), comp());

        //dp[i][j] represents max profit uptill first i events, attending a total of j
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));

        vector<int> prev_attendable(n+1, 0);

        vector<int> end_dates(n+1, 0);
        for(int i = 0; i < n; i++)
            end_dates[i+1] = events[i][1];
        
        for(int i = 1; i <= n; i++)
            prev_attendable[i] = (lower_bound(end_dates.begin(), end_dates.end(), events[i-1][0]) - end_dates.begin()) - 1;
        
        // for(int i = 1; i <= n; i++){
        //     cout << i << " : " << prev_attendable[i] << endl;
        // }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = max(dp[i-1][j], dp[prev_attendable[i]][j-1] + events[i-1][2]);
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(j > i) continue;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};