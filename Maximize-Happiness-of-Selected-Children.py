1class Solution:
2    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
3        ans = 0
4        happiness.sort(reverse=True)
5        for i in range(k):
6            ans += max(0,happiness[i]-i)
7        return ans
8