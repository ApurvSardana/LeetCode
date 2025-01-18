class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0; int j = 0;

        while(i < n && j < m)
        {
            if(nums1[i] <= nums2[j])
                nums.push_back(nums1[i++]);

            else
                nums.push_back(nums2[j++]);
        }

            while(i < n)
                nums.push_back(nums1[i++]);

            while(j < m)
                nums.push_back(nums2[j++]);

        int len = n + m;

        if(len%2 != 0)
            return (double)nums[len/2];

        else
            return (double)(nums[(len/2) - 1] + nums[len/2]) / 2.0;
    }
};