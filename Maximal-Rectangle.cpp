1class Solution {
2public:
3    int maximalRectangle(vector<vector<char>>& matrix) {
4        int n = matrix.size(), m = matrix.front().size();
5        vector<vector<int>> psr(n, vector<int> (m, 0));
6
7        for(int r = 0; r < n; r++){
8            int curr = 0;
9            for(int c = 0; c < m; c++){
10                if(matrix[r][c] == '0'){
11                    curr = 0;
12                }
13
14                else{
15                    psr[r][c] = ++curr;
16                }
17            }
18        }
19
20        int max_area = 0;
21        for(int i = 0; i < n; i++){
22            for(int j = 0; j < m; j++){
23                if(matrix[i][j] == '0') continue;
24                int width = psr[i][j];
25                int r = i;
26                while(r >= 0 && matrix[r][j] == '1'){
27                    width = min(width, psr[r][j]);
28                    max_area = max(max_area, width*(i-r+1));
29                    r--;
30                }
31            }
32        }
33
34        return max_area;
35    }
36};