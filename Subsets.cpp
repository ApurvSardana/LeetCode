1class Solution {
2public:
3    vector<vector<int>> subsets(vector<int>& nums) {
4        int n = nums.size();
5        vector<vector<int>> subsets;
6        for(int i = 0; i < (1<<n); i++){
7            vector<int> subset;
8            for(int mask = 0; mask < n; mask++){
9                if(i&(1<<mask)){
10                    subset.push_back(nums[mask]);
11                }
12            }
13
14            subsets.push_back(subset);
15        }
16
17        return subsets;
18    }
19};