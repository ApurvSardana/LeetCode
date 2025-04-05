class Solution {
public:
    int sum = 0;
    void f(vector<int> &nums, int xors, int index){
        if(index == nums.size())
            return;
        
        sum += xors^nums[index];
        f(nums, xors^nums[index], index+1);
        f(nums, xors, index+1);
    }
    int subsetXORSum(vector<int>& nums) {
        f(nums, 0, 0);
        return sum;
    }
};