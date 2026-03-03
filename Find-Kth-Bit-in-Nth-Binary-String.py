1class Solution:
2    def f(self, n : int, k : int, invert : int) -> int:
3        if n == 1 and k == 1: return 0^invert
4        middle = (1<<(n-1))
5        if k == middle: return 1^invert
6        if k < middle: return self.f(n-1,k,0)^invert
7        return self.f(n-1,2*middle-k,1)^invert
8
9    def findKthBit(self, n: int, k: int) -> str:
10        return str(self.f(n,k,0))