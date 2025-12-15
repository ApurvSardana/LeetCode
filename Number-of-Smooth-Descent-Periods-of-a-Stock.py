1class Solution:
2    def getDescentPeriods(self, a: List[int]) -> int:
3        n = len(a)
4
5        i,j,ans = 0,1,n
6
7        while j < n:
8            while j < n and a[j] == a[j-1]-1:
9                j += 1
10            
11            L = j-i
12            ans += (L*(L-1)) // 2
13
14            i = j
15            j += 1
16        
17        return ans