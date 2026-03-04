1class Solution:
2    def numSpecial(self, mat: List[List[int]]) -> int:
3        m,n = len(mat),len(mat[0])
4        oneCol,oneRow = [-1]*m,[-1]*n
5
6        for i in range(m):
7            for j in range(n):
8                if mat[i][j] and oneCol[i] == -1:
9                    oneCol[i] = j
10                elif mat[i][j]:
11                    oneCol[i] = -1
12                    break
13        
14        for j in range(n):
15            for i in range(m):
16                if mat[i][j] and oneRow[j] == -1:
17                    oneRow[j] = i
18                elif mat[i][j]:
19                    oneRow[j] = -1
20                    break
21        
22        count = 0
23        for i in range(m):
24            for j in range(n):
25                if mat[i][j] and oneCol[i] == j and oneRow[j] == i:
26                    count += 1
27        
28        return count