1class Solution:
2    def longestBalanced(self, nums: List[int]) -> int:
3        ans = 0
4        for i in range(len(nums)):
5            odd,even = set(), set()
6            for j in range(i,len(nums)):
7                odd.add(nums[j]) if nums[j]%2 else even.add(nums[j])
8                if len(odd) == len(even): ans = max(ans, j-i+1)
9        return ans