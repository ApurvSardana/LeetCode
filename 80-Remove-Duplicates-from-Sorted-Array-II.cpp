class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        bool tag = true;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] != nums[i+1])
            {
                nums[count] = nums[i+1];
                count++;
                tag = true;
            }

            else if(nums[i] == nums[i+1] && tag)
            {
                nums[count] = nums[i+1];
                count++;
                tag = false;
            }
        }
        return count;

    }
};