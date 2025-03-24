class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> new_meet;

        new_meet.push_back(meetings[0]);
        for(int i = 1; i < n; i++){
            int end_prev = new_meet.back()[1];
            int start = meetings[i][0];
            int end = meetings[i][1];

            if(start <= end_prev && end <= end_prev)
                continue;

            else if(start <= end_prev)
                new_meet.push_back({end_prev+1, end});
            
            else
                new_meet.push_back({start, end});
        }

        int minus = 0;
        for(auto v : new_meet){
            int start = v[0];
            int end = v[1];

            minus += (end-start+1);
        }

        return days-minus;
    }
};