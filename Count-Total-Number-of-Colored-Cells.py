class Solution:
    def coloredCells(self, n: int) -> int:
        dp = []
        dp.append(1)

        for i in range(n-1):
            dp.append(dp[-1] + 4*(i+1))

        return dp[-1]          