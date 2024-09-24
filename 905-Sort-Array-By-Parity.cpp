class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int p = 0;
        while(l < nums.size())
        {
            if(nums[l] % 2 == 0)
            {
                swap(nums[l], nums[p]);
                l++;
                p++;
            }
            else
            {
                l++;
            }
        }
        return nums;
    }
};