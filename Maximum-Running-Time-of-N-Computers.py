1class Solution:
2    def maxRunTime(self, n: int, batteries: List[int]) -> int:
3        batteries.sort()
4        live = batteries[-n : ]
5        s = sum(batteries[0 : -n])
6
7        ans = 0
8        index = 0
9        for i in range(n-1):
10            if(s >= (i+1)*(live[i+1]-live[i])):
11                s -= (i+1)*(live[i+1]-live[i])
12                index = i+1
13
14            else:
15                break
16            
17        ans = live[index] + (s//(index+1))
18        return ans