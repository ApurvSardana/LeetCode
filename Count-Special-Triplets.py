1class Solution:
2    def specialTriplets(self, nums: List[int]) -> int:
3        n = len(nums)
4        back = [0]*n
5        front = [0]*n
6
7        D1, D2 = {}, {}
8
9        for i in range(n):
10            val = nums[i]
11
12            back[i] = D1.get(val*2, 0)
13            
14            D1[val] = D1.get(val, 0) + 1
15        
16        for i in range(n-1, -1, -1):
17            val = nums[i]
18
19            front[i] = D2.get(val*2, 0)
20
21            D2[val] = D2.get(val, 0) + 1
22        
23        ans,MOD = 0, 1e9 + 7
24        for i in range(n):
25            ans = (ans + front[i]*back[i])%MOD
26
27        return int(ans)