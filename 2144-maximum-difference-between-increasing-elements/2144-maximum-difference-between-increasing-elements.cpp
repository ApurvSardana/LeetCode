class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(); int ans = -1; int greatest_element = -1;
        for(int i = n-1; i >= 0; i--){
            ans = max(ans, greatest_element-nums[i]);
            greatest_element = max(greatest_element, nums[i]);
        }

        return (ans <= 0) ? -1 : ans;
    }
};