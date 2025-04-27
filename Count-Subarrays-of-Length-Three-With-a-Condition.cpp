class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i <= n-3; i++){
            int a = nums[i]; int b = nums[i+1]; int c = nums[i+2];
            count += (2*(a+c) == b);
        }
        return count;
    }
};