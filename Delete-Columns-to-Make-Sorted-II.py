1class Solution:
2    def minDeletionSize(self, strs: List[str]) -> int:
3        n,m,count = len(strs), len(strs[0]), 0
4        settled = [False]*(n-1)
5        for j in range(m):
6            delThis = False
7            for i in range(1,n):
8                if strs[i][j] < strs[i-1][j] and not settled[i-1]:
9                    count += 1
10                    delThis = True
11                    break
12            
13            if not delThis:
14                for i in range(1,n):
15                    if strs[i][j] > strs[i-1][j]:
16                        settled[i-1] = True
17        
18        return count
19                