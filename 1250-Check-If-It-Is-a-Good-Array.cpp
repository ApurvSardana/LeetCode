class Solution {
public:
    bool isGoodArray(vector<int>& nums)
    {
       int g = 0;
        int min = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                return true;
            
        if(nums[i] < min)
        min = nums[i];
        }
        g = __gcd(min, nums[0]);
        for(int i = 1;i < nums.size(); i++)
        {
            g = __gcd(g, nums[i]); 
            if(g == 1)
            return true;
        }
        return false;
    }
};