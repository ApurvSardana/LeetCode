class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        int p = INT_MIN;
        int size = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < size; i++)
        {
            pq.push({points[i][1], points[i][0]});
        }

        while(!pq.empty())
        {
            if(pq.top().second > p || (pq.top().second == INT_MIN && ans == 0))
            {
            ans++;
            p = pq.top().first;
            }

            pq.pop();
        }

        return ans;
    }
};