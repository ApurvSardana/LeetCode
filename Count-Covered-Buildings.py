1class Solution:
2    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
3        row,col = [[inf,-inf] for _ in range(n+1)], [[inf,-inf] for _ in range(n+1)]
4
5        for r,c in buildings:
6            row[r][0],row[r][1] = min(row[r][0], c), max(row[r][1], c)
7            col[c][0],col[c][1] = min(col[c][0], r), max(col[c][1], r)
8        
9        ans = 0
10        for r,c in buildings:
11            ans += int(row[r][0] < c and row[r][1] > c and col[c][0] < r and col[c][1] > r)
12        
13        return ans