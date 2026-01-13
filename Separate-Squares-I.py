1class Solution:
2    def separateSquares(self, squares: List[List[int]]) -> float:
3        epsilon = 5e-6
4
5        ans,left,right = 0.0,inf,-inf
6
7        for x,y,l in squares:
8            left = min(left,y)
9            right = max(right,y+l)
10
11        def LA(squares,Y) -> float:
12            area = 0.0
13            for x,y,l in squares:
14                bottom_edge,top_edge = y,y+l
15
16                if bottom_edge >= Y:
17                    continue
18                
19                top_edge = min(top_edge,Y)
20                area += (top_edge-bottom_edge)*l
21            
22            return area
23        
24        def UA(squares,Y) -> float:
25            area = 0.0
26            for x,y,l in squares:
27                bottom_edge,top_edge = y,y+l
28            
29                if top_edge <= Y:
30                    continue
31            
32                bottom_edge = max(bottom_edge,Y)
33                area += (top_edge-bottom_edge)*l
34            
35            return area
36
37        while right-left > epsilon:
38            Y = (left + right) / 2.0
39            lower_area,upper_area = LA(squares,Y),UA(squares,Y)
40
41            if lower_area < upper_area:
42                left = Y+epsilon
43            
44            else:
45                right = Y-epsilon
46
47        return left