1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4        int n = nums.size();
5        int count = 0;
6        for(int i = 0; i < n; i++){
7            if(nums[i] == 0) count++;
8            else{
9                nums[i-count] = nums[i];
10            }
11        }
12
13        for(int i = n-1; i >= n-count; i--){
14            nums[i] = 0;
15        }
16    }
17};
18