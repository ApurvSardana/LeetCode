class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        pq.push(nums[i]);

        for(int i = 0; i < k; i++)
        {
            int temp = pq.top();
            ans += temp;
            pq.pop();
            pq.push(ceil((double)(temp) / 3.0)); 
        }
        return ans;
    }
};