1class Solution:
2    def minPairSum(self, nums: List[int]) -> int:
3        nums.sort()
4        max_sum = 0
5
6        i,j = 0,len(nums)-1
7        while i < j:
8            max_sum = max(max_sum, nums[i]+nums[j])
9            i += 1
10            j -= 1
11
12        return max_sum