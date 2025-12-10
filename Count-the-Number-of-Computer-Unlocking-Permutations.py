1class Solution:
2    MOD = 1e9 + 7
3
4    def f(self, x : int) -> int:
5        if x <= 1:
6            return 1
7        
8        return x*self.f(x-1) % self.MOD
9
10    def countPermutations(self, complexity: List[int]) -> int:
11        complexity_new = [x - complexity[0] for x in complexity]
12
13        for i in range(1, len(complexity)):
14            if complexity_new[i] <= 0:
15                return int(0)
16        
17        return int(self.f(len(complexity)-1))