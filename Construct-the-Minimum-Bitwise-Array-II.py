1class Solution:
2    def minBitwiseArray(self, nums: List[int]) -> List[int]:
3        ans = []
4        for num in nums:
5            if num == 2:
6                ans.append(-1)
7                continue
8            
9            for j in range(32):
10                if(num & (1 << j) == 0):
11                    ans.append(num-(1 << (j-1)))
12                    break
13        return ans