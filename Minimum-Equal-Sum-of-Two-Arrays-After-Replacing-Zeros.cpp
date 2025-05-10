class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);

        int z1 = count(nums1.begin(), nums1.end(), 0);
        int z2 = count(nums2.begin(), nums2.end(), 0);

        long long min1 = sum1 + z1;
        long long max1 = (z1 == 0) ? sum1 : LLONG_MAX;

        long long min2 = sum2 + z2;
        long long max2 = (z2 == 0) ? sum2 : LLONG_MAX;

        if(min1 > max2 || min2 > max1) return -1;

        return max(min1, min2);
    }
};