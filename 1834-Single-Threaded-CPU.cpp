class comp
{
    public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        if(a[1] == b[1])
        return a[2] > b[2];

        return a[1] > b[1];
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int size = tasks.size();
        vector<int> ans;

        int max = INT_MIN;
        long long sum = 0;
        for(int i = 0; i < size; i++)
        {
            if(tasks[i][0] > max)
            max = tasks[i][0];

            sum += tasks[i][1];
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<vector<int>, vector<vector<int>>, comp> pq;

        int k = 0;
        long time = tasks[0][0];
        while(k<size || !pq.empty())
        {
            while(k < size && tasks[k][0] <= time)
            {
                pq.push(tasks[k]);
                k++;
            }

            if(!pq.empty())
            {
            ans.push_back(pq.top()[2]);
            time += pq.top()[1];
            pq.pop();
            }

            else if(k < size)
            {
                time = tasks[k][0];
            }
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top()[2]);
            pq.pop();
        }
        return ans;
    }
};