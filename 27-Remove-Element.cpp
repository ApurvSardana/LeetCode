class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int k = 0;

        while(i <= j)
        {
            if(nums[i] == val)
            {
                swap(nums[i], nums[j]);
                j--;
            }

            else
            {
                k++;
                i++;
            }
        }
        cout << k;
        return k;
    }
};