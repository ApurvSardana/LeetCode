class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        f = []
        for i in range(n*n):
            f.append(0)
        
        for i in range(n):
            for j in range(n):
                f[grid[i][j]-1] += 1
        
        a = -1
        b = -1
        for i in range(n*n):
            if f[i] == 2:
                a = i+1
            
            elif f[i] == 0:
                b = i+1
        
        return [a, b]
        