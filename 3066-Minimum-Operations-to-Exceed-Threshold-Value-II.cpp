class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        int operations = 0;
        while(!pq.empty()){
            long long min1 = pq.top();
            if(min1 >= k){
                return operations;
            }

            pq.pop();
            long long min2 = 0;
            if(!pq.empty()){
                min2 = pq.top();
                pq.pop();
            }

            long long x = min1*2 + min2;
            operations++;

            pq.push(x);
        }
        return operations;
    }
};