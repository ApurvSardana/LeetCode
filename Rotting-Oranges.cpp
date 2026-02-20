1class Solution {
2public:
3    bool f(vector<vector<int>> grid, int time){
4        int m = grid.size(), n = grid.front().size();
5        vector<vector<int>> new_grid = grid;
6        for(int i = 0; i < time; i++){
7            // cout << "After " << i+1 << " : \n";
8            for(int r = 0; r < m; r++){
9                for(int c = 0; c < n; c++){
10                    if(grid[r][c] != 2) continue;
11                    if(r+1 < m && grid[r+1][c] == 1) new_grid[r+1][c] = 2;
12                    if(r-1 >= 0 && grid[r-1][c] == 1) new_grid[r-1][c] = 2;
13                    if(c+1 < n && grid[r][c+1] == 1) new_grid[r][c+1] = 2;
14                    if(c-1 >= 0 && grid[r][c-1] == 1) new_grid[r][c-1] = 2;
15                }
16            }
17
18            grid = new_grid;
19            // for(int i = 0; i < m; i++){
20            //     for(int j = 0; j < n; j++)
21            //         cout << grid[i][j] << " ";
22            //     cout << endl;
23            // }
24            // cout << endl;
25        }
26
27
28        int count = 0;
29        for(int i = 0; i < m; i++)
30            for(int j = 0; j < n; j++)
31                count += (grid[i][j] == 1);
32        
33        return (count == 0);
34    }
35    int orangesRotting(vector<vector<int>>& grid) {
36        int left = 0, right = 100;
37        // for(int i = 0; i < 10; i++){
38            // cout << 1 << " : " << f(grid,10) << endl;
39        // }
40        while(left <= right){
41            int mid = (left+right)/2;
42
43            if(f(grid,mid)){
44                right = mid-1;
45            }else{
46                left = mid+1;
47            }
48        }
49
50        return (left <= 100) ? left : -1;
51    }
52};