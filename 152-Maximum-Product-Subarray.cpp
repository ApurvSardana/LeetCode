class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long double prod = 1;
        long double mprod = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            prod = prod * nums[i];
            mprod = max(mprod, prod);
            if(prod == 0) prod = 1;
        }

        prod = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            prod = prod * nums[i];
            mprod = max(mprod, prod);
            if(prod == 0) prod = 1;
        }
        return (int)mprod;
    }
};