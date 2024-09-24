class Solution {
public:
// template <class T>
// // void Swap(T &a, T &b)
// // {
// //     T temp = a;
// //     a = b;
// //      b = temp;
// // }

    void sortColors(vector<int>& nums) {
        int l = 0; int m = 0; int h = nums.size() - 1;
        while(m <= h)
        {
            if(nums[m] == 0)
            {
                swap(nums[m], nums[l]);
                l += 1;
                m += 1;
            }

            else if(nums[m] == 1)
            {
                m += 1;
            }

            else if(nums[m] == 2)
            {
                swap(nums[m], nums[h]);
                h -= 1;
            }
        }
        
    }
};