1class Solution:
2    def maxSumTrionic(self, nums: List[int]) -> int:
3        n = len(nums)
4        ps = [0]
5        for num in nums:
6            ps.append(ps[-1] + num)
7
8        max_inc_front, max_dec_front, max_dec_back = [-inf]*n, [1]*n, [-inf]*n
9
10        max_dec_back[0] = nums[0]
11        for i in range(1,n):
12            if nums[i] > nums[i-1]: max_dec_back[i] = max(nums[i], nums[i] + max_dec_back[i-1])
13            else: max_dec_back[i] = nums[i]
14        
15        max_inc_front[-1] = nums[-1]
16        for i in range(n-2,-1,-1):
17            if nums[i] < nums[i+1]: max_inc_front[i] = max(nums[i], nums[i] + max_inc_front[i+1])
18            else: max_inc_front[i] = nums[i]
19
20        #Length
21        for i in range(n-2,-1,-1):
22            if nums[i] > nums[i+1]: max_dec_front[i] = 1 + max_dec_front[i+1]
23        
24        ans = -inf
25        for i in range(1,n-2):
26            j = i + max_dec_front[i] - 1
27            if j == i: continue
28            s1 = max_dec_back[i]
29            if s1 == nums[i]: 
30                if nums[i-1] >= nums[i]: continue
31                s1 += max_dec_back[i-1]
32            s2 = ps[j] - ps[i+1]
33            s3 = max_inc_front[j]
34            if s3 == nums[j]:
35                if j == n-1: continue
36                if nums[j+1] <= nums[j]: continue
37                s3 += max_inc_front[j+1]
38            
39            ans = max(ans, s1+s2+s3)
40        
41        return ans