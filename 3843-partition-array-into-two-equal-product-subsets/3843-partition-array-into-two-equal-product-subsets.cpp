class Solution {
public:
    int n;
    bool f(vector<unsigned long long> &nums2, unsigned long long target, int index, unsigned long long p1, unsigned long long p2){
        if(index >= n) return (p1 == p2 && p1 == target);

        return f(nums2, target, index+1, p1*nums2[index], p2) || f(nums2, target, index+1, p1, p2*nums2[index]);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n = nums.size();
        vector<unsigned long long> nums2(n);
        for(int i = 0; i < n; i++) nums2[i] = (unsigned long long)nums[i];
        return f(nums2, target, 0, 1ULL, 1ULL);
    }
};