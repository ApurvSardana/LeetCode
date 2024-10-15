class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        int len = s.length();
        priority_queue <int, vector<int>, greater<int>> pq_zeros;
        priority_queue <int, vector<int>, greater<int>> pq_ones;

        for(int i = 0; i < len; i++)
        {
            if(s[i] == '0')
            pq_zeros.push(i);

            else
            pq_ones.push(i);
        }

        if(pq_zeros.empty() || pq_ones.empty())
        return count;

        while(!pq_zeros.empty())
        {
            if(pq_zeros.top() < pq_ones.top())
            pq_zeros.pop();

            else
            {
                count += pq_zeros.top() - pq_ones.top();
                pq_ones.push(pq_zeros.top());
                pq_zeros.pop();
                pq_ones.pop();
            }
        }

        return count;
    }
};