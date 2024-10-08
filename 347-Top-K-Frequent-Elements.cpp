class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto n : m)
        {
            pq.push({n.second, n.first});
        }
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};