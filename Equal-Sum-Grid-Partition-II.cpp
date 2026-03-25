1class Solution {
2public:
3    using ll = long long;
4    ll m, n;
5    bool f1(vector<vector<int>> &grid){
6        bool ok = false;
7        vector<ll> ps = {0LL};
8
9        for(int j = 0; j < n; j++){
10            ll col_sum = 0LL;
11            for(int i = 0; i < m; i++){
12                col_sum += grid[i][j];
13            }
14
15            ps.push_back(ps.back() + col_sum);
16        }
17
18        set<ll> st;
19
20        for(int j = 1; j < n; j++){
21            for(int i = 0; i < m; i++){
22                st.insert(grid[i][j-1]);
23            }
24
25            ok |= (2LL*ps[j] == ps[n]);
26
27            if(j == 1){
28                ok |= (grid[0][0] == ps[j] - (ps[n]-ps[j])) or (grid[m-1][0] == ps[j] - (ps[n]-ps[j]));
29            }
30
31            else{
32                // cout << j << " : " << ps[j] - (ps[n]-ps[j]) << " ";
33                ok |= (st.find(ps[j] - (ps[n]-ps[j])) != st.end());
34                // cout << ok << endl;
35            }
36        }
37
38        st.clear();
39
40        for(int j = n-1; j > 0; j--){
41            for(int i = 0; i < m; i++){
42                st.insert(grid[i][j]);
43            }
44
45            ok |= (2LL*ps[j] == ps[n]);
46
47            if(j == n-1){
48                ok |= (grid[0][n-1] == (ps[n]-ps[j]) - ps[j]) or (grid[m-1][n-1] == (ps[n]-ps[j]) - ps[j]);
49            }
50
51            else{
52                // cout << j << " : " << (ps[n]-ps[j]) - ps[j] << " ";
53                ok |= (st.find((ps[n]-ps[j]) - ps[j]) != st.end());
54                // cout << ok << endl;
55            }
56        }
57
58        // cout << "col : "  << ok << endl;
59        return ok;
60    }
61
62    bool f2(vector<vector<int>> &grid){
63        bool ok = false;
64        vector<ll> ps = {0LL};
65
66        for(int i = 0; i < m; i++){
67            ll row_sum = 0LL;
68            for(int j = 0; j < n; j++){
69                row_sum += grid[i][j];
70            }
71
72            ps.push_back(ps.back() + row_sum);
73        }
74
75        set<ll> st;
76
77        for(int i = 1; i < m; i++){
78            for(int j = 0; j < n; j++){
79                st.insert(grid[i-1][j]);
80            }
81
82            ok |= (2LL*ps[i] == ps[m]);
83
84            if(i == 1){
85                ok |= (grid[0][0] == ps[i] - (ps[m]-ps[i])) or (grid[0][n-1] == ps[i] - (ps[m]-ps[i]));
86            }
87
88            else{
89                // cout << j << " : " << ps[j] - (ps[n]-ps[j]) << " ";
90                ok |= (st.find(ps[i] - (ps[m]-ps[i])) != st.end());
91                // cout << ok << endl;
92            }
93        }
94
95        st.clear();
96
97        for(int i = m-1; i > 0; i--){
98            for(int j = 0; j < n; j++){
99                st.insert(grid[i][j]);
100            }
101
102            ok |= (2LL*ps[i] == ps[m]);
103
104            if(i == m-1){
105                ok |= (grid[m-1][0] == (ps[m]-ps[i]) - ps[i]) or (grid[m-1][n-1] == (ps[m]-ps[i]) - ps[i]);
106            }
107
108            else{
109                // cout << j << " : " << (ps[n]-ps[j]) - ps[j] << " ";
110                ok |= (st.find((ps[m]-ps[i]) - ps[i]) != st.end());
111                // cout << ok << endl;
112            }
113        }
114
115        // cout << "row : "  << ok << endl;
116        return ok;
117    }
118
119    bool canPartitionGrid(vector<vector<int>>& grid) {
120        m = grid.size(), n = grid.front().size();
121
122        if(m == 1){
123            vector<ll> ps = {0};
124            for(auto num : grid[0]) ps.push_back(ps.back() + num);
125            bool ok = false;
126            for(int c = 1; c < n; c++){
127                ok |= (2LL*ps[c] == ps[n]);
128
129                ok |= (grid[0][0] == -(ps[n] - 2LL*ps[c])) or (grid[0][c-1] == -(ps[n] - 2LL*ps[c]));
130                ok |= (grid[0][n-1] == ps[n] - 2LL*ps[c]) or (grid[0][c] == ps[n] - 2LL*ps[c]);
131            }
132
133            return ok;
134        }
135
136        else if(n == 1){
137            vector<ll> ps = {0};
138            for(auto num : grid) ps.push_back(ps.back() + num[0]);
139            bool ok = false;
140            for(int r = 1; r < m; r++){
141                ok |= (2LL*ps[r] == ps[m]);
142
143                ok |= (grid[0][0] == -(ps[m] - 2LL*ps[r])) or (grid[r-1][0] == -(ps[m] - 2LL*ps[r]));
144                ok |= (grid[m-1][0] == ps[m] - 2LL*ps[r]) or (grid[r][0] == ps[m] - 2LL*ps[r]);
145            }
146
147            return ok;
148        }
149
150        bool ok = false;
151
152        //Vertical Cut Check
153        ok |= f1(grid);
154
155        //Horizontal Cut Check
156        ok |= f2(grid);
157
158        return ok;
159    }
160};