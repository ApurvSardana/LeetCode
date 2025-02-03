class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_increasing = 1, max_decreasing = 1;

        for(int i = 0; i < n; i++){
            int increasing = 1, decreasing = 1;
            for(int j = i; j < n - 1; j++){
                if(nums[j] < nums[j+1] && decreasing == 1)
                    increasing++;

                else if(nums[j] > nums[j+1] && increasing == 1)
                    decreasing++;

                else break;
            }
            max_increasing = max(max_increasing, increasing);
            max_decreasing = max(max_decreasing, decreasing);
        }
        return max(max_increasing, max_decreasing);
    }
};