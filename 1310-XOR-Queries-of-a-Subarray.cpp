class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> ps(arr.size());

        ps[0] = arr[0];
        for(int i = 1; i < arr.size(); i++)
        ps[i] = arr[i]^ps[i - 1];

        for(auto n : queries)
        {
            if(n[0] == 0)
            ans.push_back(ps[n[1]]);

            else
            ans.push_back(ps[n[1]]^ps[n[0] - 1]);
        }

        return ans;
    }
};