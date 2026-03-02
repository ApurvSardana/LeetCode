1class Solution:
2    def minSwaps(self, grid: List[List[int]]) -> int:
3        n = len(grid)
4        p = []
5
6        for i in range(n):
7            last_one = -1
8            for j in range(n-1,-1,-1):
9                if grid[i][j] == 1:
10                    last_one = j
11                    break
12            p.append(last_one)
13
14        swaps = 0
15        for i in range(n):
16            ok,index = False,-1
17            for j in range(i,n):
18                if p[j] <= i:
19                    ok = True
20                    index = j
21                    swaps += j-i
22                    break
23            if not ok: return -1
24            p.insert(p[index],i)
25            p.pop(index+1)
26        
27        return swaps