class comp
{
    public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
    return a[1] > b[1];
    }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int> answer;

        sort(items.begin(), items.end(), comp());

        for(auto p : queries)
        {
            int i = 0; 
            while(i < n && items[i][0] > p)
            i++;

            if(i == n)
            answer.push_back(0);

            else
            answer.push_back(items[i][1]);
        }

        return answer;
    }
};