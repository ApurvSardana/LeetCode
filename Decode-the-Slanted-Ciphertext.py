1class Solution:
2    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
3        cols = len(encodedText) // rows
4        # g = [[' ']*cols for _ in range(rows)]
5
6        # for i in range(rows):
7        #     for j in range(cols):
8        #         g[i][j] = encodedText[i*cols + j]
9        
10        ans = []
11        for i in range(0,cols):
12            r,c = 0,i
13            while r < rows and c < cols:
14                ans.append(encodedText[r*cols + c])
15                r += 1
16                c += 1
17        
18        return ''.join(ans).rstrip()