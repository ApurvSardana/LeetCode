1class Solution:
2    def countTrapezoids(self, points: List[List[int]]) -> int:
3        MOD = 1000000007
4
5        f = {}
6
7        for point in points:
8            y = point[1]
9            if y in f:
10                f[y] += 1
11            else:
12                f[y] = 1
13        
14        Y = []
15
16        for x in f.values():
17            Y.append((x*(x-1))//2)
18        
19        s = Y[0]
20
21        ans = 0
22        for i in range(1, len(Y)):
23            ans = (ans + (Y[i]*s)%MOD) % MOD
24            s = (s + Y[i]) % MOD
25
26        return int(ans) 