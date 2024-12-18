class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = events[0][0];
        int maxi = events[0][1];

        for(int i = 1; i < events.size(); i++)
            if(events[i][1]  - events[i - 1][1]> maxi || (events[i][1] - events[i - 1][1] == maxi && events[i][0] < ans))
            {
                ans = events[i][0];
                maxi = events[i][1] - events[i - 1][1];
            }
        return ans;
    }
};