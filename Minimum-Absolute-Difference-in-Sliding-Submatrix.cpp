1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
4        int m = grid.size(), n = grid.front().size();
5        vector<vector<int>> ans;
6
7        for(int r = 0; r+k-1 < m; r++){
8            vector<int> row_ans;
9            map<int, int> mp;
10
11            //Initialize map with sub-grid (filter) 
12            for(int i = r; i <= r+k-1; i++){
13                for(int j = 0; j < k; j++){
14                    mp[grid[i][j]]++;
15                }
16            }
17            
18            int diff = 2e5;
19            if(mp.size() == 1) diff = 0;
20            else{
21                for(auto it = mp.begin(); it != mp.end(); it++){
22                    if(it != mp.begin()){
23                        diff = min(diff, abs(it->first - prev(it)->first));
24                    }
25                }
26            }
27
28            row_ans.push_back(diff);
29            //Slide the filter
30            int left = 0, right = k;
31            while(right < n){
32                diff = 2e5;
33                for(int i = r; i <= r+k-1; i++){
34                    mp[grid[i][left]]--;
35                    if(mp[grid[i][left]] == 0) mp.erase(grid[i][left]);
36                }
37
38                for(int i = r; i <= r+k-1; i++){
39                    mp[grid[i][right]]++;
40                }
41
42                if(mp.size() == 1) diff = 0;
43                else{
44                    for(auto it = mp.begin(); it != mp.end(); it++){
45                        if(it != mp.begin()){
46                            diff = min(diff, abs(it->first - prev(it)->first));
47                        }
48                    }
49                }
50
51                row_ans.push_back(diff);
52
53                left++;
54                right++;
55            }
56
57            ans.push_back(row_ans);
58        }
59
60        return ans;
61    }
62};