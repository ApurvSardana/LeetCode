1class Solution:
2    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
3        horizontal_differences,MOD = set(),int(1e9 + 7)
4
5        hFences.append(1)
6        hFences.append(m)
7        vFences.append(1)
8        vFences.append(n)
9
10        hFences.sort()
11        vFences.sort()
12
13        for i in range(len(hFences)):
14            for j in range(i+1,len(hFences)):
15                horizontal_differences.add(hFences[j]-hFences[i])
16            
17        ans = -1
18
19        for i in range(len(vFences)):
20            for j in range(i+1,len(vFences)):
21                diff = vFences[j]-vFences[i]
22                if diff in horizontal_differences:
23                    ans = max(ans,diff*diff)
24
25        return ans%MOD if ans != -1 else ans