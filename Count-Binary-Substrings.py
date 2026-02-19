1class Solution:
2    def countBinarySubstrings(self, s: str) -> int:
3        n,ans = len(s),0
4        for center in range(n-1):
5            if s[center] != s[center+1]:
6                left,right = center,center+1
7                while left-1 >= 0 and right+1 < n and s[left-1] == s[left] and s[right] == s[right+1]:
8                    left -= 1
9                    right += 1
10                ans += right-center
11        return ans