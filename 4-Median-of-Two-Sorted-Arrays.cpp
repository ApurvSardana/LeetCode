class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(int num : nums1)
        nums.push_back(num);

        for(int num2 : nums2)
        nums.push_back(num2);

        sort(nums.begin(), nums.end());

        int len = nums.size();

        if(len%2 != 0)
        return nums[len/2];

        else
        return (double)(nums[(len/2) - 1] + nums[len/2]) / 2;
    }
};