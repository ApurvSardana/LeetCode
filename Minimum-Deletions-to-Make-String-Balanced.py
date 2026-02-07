1class Solution:
2    def minimumDeletions(self, s: str) -> int:
3        nums = [ord(ch)-ord('a') for ch in s]
4        dp = []
5
6        for num in nums:
7            index = bisect.bisect_right(dp,num,lo=0,hi=len(dp))
8            if index < len(dp): dp[index] = num
9            else: dp.append(num)
10        
11        return len(s) - len(dp)