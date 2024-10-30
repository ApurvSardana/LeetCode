class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<int> pq;
        int sum = 0;

        for(int i = 0; i < size; i++)
        pq.push(-nums[i]);

        for(int i = 0; i < k; i++)
        {
            int a = pq.top();

            pq.pop();

            pq.push(-a);
        }

        while(!pq.empty())
        {
            sum -= pq.top();
            pq.pop();
        }

        return sum;
    }
};