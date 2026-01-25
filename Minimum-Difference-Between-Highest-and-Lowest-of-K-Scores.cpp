1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        int diff = INT_MAX;
7        for(int i = 0, j = 0; j < n; j++){
8            if(j-i+1 == k){
9                diff = min(diff,nums[j]-nums[i]);
10                i++;
11            }
12        }
13        return diff;
14    }
15};