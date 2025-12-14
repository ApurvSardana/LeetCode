1class Solution:
2    def numberOfWays(self, corridor: str) -> int:
3        n,MOD = len(corridor), 1e9+7
4        consP = [0]*(n+1)
5
6        consP[n-1] = int(corridor[n-1] == 'P')
7
8        for i in range(n-2,-1,-1):
9            consP[i] = 0 if corridor[i] == 'S' else 1+consP[i+1]
10        
11        pos = []
12        count = 0
13        for i in range(n):
14            count += int(corridor[i] == 'S')
15            if count == 2:
16                pos.append(i)
17                count = 0
18        
19        if count != 0:
20            return 0
21            
22        if pos:
23            x = pos.pop()
24            if not pos:
25                return 1
26
27        ans = 0
28        for p in pos:
29            if ans == 0:
30                ans = consP[p+1] + 1
31            else:
32                ans = (ans*(consP[p+1]+1))%MOD
33            
34        return int(ans)