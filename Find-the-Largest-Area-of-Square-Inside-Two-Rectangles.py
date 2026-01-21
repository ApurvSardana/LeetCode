1class Solution:
2    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
3        n = len(bottomLeft)
4        rectangles = [[bottomLeft[i][0],bottomLeft[i][1], topRight[i][0],topRight[i][1]] for i in range(n)]
5
6        rectangles.sort()
7        max_area = 0
8        for i in range(n):
9            for j in range(i+1,n):
10                if rectangles[j][0] > rectangles[i][2]: continue
11                if rectangles[j][1] > rectangles[i][3]: continue
12                if rectangles[j][3] < rectangles[i][1]: continue
13
14                BLx = max(rectangles[i][0],rectangles[j][0])
15                BLy = max(rectangles[i][1],rectangles[j][1])
16                TRx = min(rectangles[i][2],rectangles[j][2])
17                TRy = min(rectangles[i][3],rectangles[j][3])
18
19                side = min(TRx-BLx,TRy-BLy)
20                max_area = max(max_area,side*side)
21        return max_area
22