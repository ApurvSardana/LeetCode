1class Solution:
2    def minFlips(self, s: str) -> int:
3        n = len(s)
4        start_0, start_1, end_0, end_1 = [0]*n, [0]*n, [0]*n, [0]*n
5
6        start_0[0] = int(s[0] != '0')
7        start_1[0] = int(s[0] != '1')
8        end_0[-1] = int(s[-1] != '0')
9        end_1[-1] = int(s[-1] != '1')
10
11        for i in range(1,n):
12            start_0[i] = start_0[i-1] + int((i%2 == 0 and s[i] == '1') or (i%2 == 1 and s[i] == '0'))
13            start_1[i] = start_1[i-1] + int((i%2 == 0 and s[i] == '0') or (i%2 == 1 and s[i] == '1'))
14        
15        for i in range(n-2,-1,-1):
16            end_0[i] = end_0[i+1] + int((i%2 == (n-1)%2 and s[i] == '1') or (i%2 != (n-1)%2 and s[i] == '0'))
17            end_1[i] = end_1[i+1] + int((i%2 == (n-1)%2 and s[i] == '0') or (i%2 != (n-1)%2 and s[i] == '1'))
18        
19        ans = min(start_0[-1], start_1[-1])
20        for i in range(n-1):
21            ans = min(ans, start_0[i] + end_1[i+1], start_1[i] + end_0[i+1])
22        
23        return ans