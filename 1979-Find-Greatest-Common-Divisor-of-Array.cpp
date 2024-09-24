class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini, maxi;
        mini = maxi = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxi)
            maxi = nums[i];

            else if(nums[i] <= mini)
            mini = nums[i];
        }
        return __gcd(mini, maxi);
    }
};