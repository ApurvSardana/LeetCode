class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool isEven = (nums[0]%2 == 0);

        for(int i = 1; i < n; i++){
            if((isEven && (nums[i]%2 != 0)) || (!isEven && (nums[i]%2 == 0)))
                isEven = !isEven;
            
            else
                return false;
        }
        return true;
    }
};