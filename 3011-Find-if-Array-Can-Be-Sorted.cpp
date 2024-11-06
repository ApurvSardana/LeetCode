class Solution {
public:
    int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        if (num & 1) { // Check if the least significant bit is 1
            count++;
        }
        num >>= 1; // Right shift the number
    }
    return count;
}
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n-1; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(nums[j] < nums[j-1] && countOnes(nums[j]) == countOnes(nums[j-1]))
                swap(nums[j], nums[j-1]);

                else if(nums[j] < nums[j-1])
                return false;
            }
        }
        return true;
    }
};