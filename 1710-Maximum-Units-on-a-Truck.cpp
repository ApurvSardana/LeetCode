class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        priority_queue <pair<int, int>> pq;

        for(auto n : boxTypes)
        pq.push({n[1], n[0]});

        while(!pq.empty() && truckSize > 0)
        {
            pair<int, int> num = pq.top();
            if(truckSize >= num.second)
            {
                ans += num.first * num.second;
                truckSize -= num.second;
            }

            else
            {
                ans += truckSize * num.first;
                truckSize = 0;
            }
            pq.pop();
        }
        return ans;
    }
};