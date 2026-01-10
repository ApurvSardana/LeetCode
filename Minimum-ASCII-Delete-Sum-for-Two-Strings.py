1class Solution:
2    def minimumDeleteSum(self, s1: str, s2: str) -> int:
3        n,m = len(s1),len(s2)
4        dp = [[0]*(m+1) for _ in range(n+1)]
5
6        for i in range(1,n+1):
7            for j in range(1,m+1):
8                dp[i][j] = max(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
9                if s1[i-1] == s2[j-1]:
10                    dp[i][j] = dp[i-1][j-1] + ord(s1[i-1])
11
12        t1,t2 = 0,0
13        for i in range(n):
14            t1 += ord(s1[i])
15        for i in range(m):
16            t2 += ord(s2[i])
17
18        return t1+t2-2*dp[n][m]