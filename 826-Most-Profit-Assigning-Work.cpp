class comp
    {
        public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if(a.first > b.first)
            return true;

            else if(a.first < b.first)
            return false;

            else if(a.second < b.second)
            return true;

            else
            return false;
        }
    };
    
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int max_profit = 0;
        int n = profit.size();
        int m = worker.size();

        vector<pair<int, int>> pd(n);

        for(int i = 0; i < n; i++)
        pd[i] = {profit[i], difficulty[i]};

        sort(pd.begin(), pd.end(), comp());
        sort(worker.begin(), worker.end(), greater<int>());

        for(auto p : pd)
        cout << p.first << "," << p.second << " ";

        cout << endl;

        for(auto p : worker)
        cout << p << " ";

        int i = 0; int j = 0;
        while(i < m && j < n)
        {
            if(worker[i] >= pd[j].second)
            {
            max_profit += pd[j].first;
            i++;
            }
            
            else
            j++;
        }
        return max_profit;     
    }
};