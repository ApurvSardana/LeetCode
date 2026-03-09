1class Solution {
2public:
3    int Query(vector<int> &tree, int node, int node_low, int node_high, int query_low, int query_high){
4        if(node_low > query_high or node_high < query_low) return 0;
5
6        if(node_low >= query_low and query_high >= node_high){
7            return tree[node];
8        }
9
10        int last_left = (node_low + node_high)/2;
11        return Query(tree, 2*node, node_low, last_left, query_low, query_high)
12             + Query(tree, 2*node+1, last_left+1, node_high, query_low, query_high);
13    }
14
15    void update(vector<int> &tree, vector<int> &nums, int node, int val, int offset){
16        nums[node] = val;
17        auto f = [&](int a_node, int v) -> void{
18            tree[a_node] = v;
19            a_node /= 2;
20            while(a_node >= 1){
21                tree[a_node] = tree[2*a_node] + tree[2*a_node+1];
22                a_node /= 2;
23            }
24        };
25
26        if(node == 0){
27            if(nums[node+1] > nums[node] and nums[node+1] > nums[node+2]){
28                f(node+offset+1,1);
29            }
30
31            else{
32                f(node+offset+1,0);
33            }
34        }
35
36        else if(node == nums.size()-1){
37            if(nums[node-1] > nums[node] and nums[node-1] > nums[node-2]){
38                f(node+offset-1,1);
39            }
40
41            else{
42                f(node+offset-1,0);
43            }
44        }
45
46        else{
47            //Check node
48            if(nums[node] > nums[node-1] and nums[node] > nums[node+1]){
49                f(node+offset,1);
50            }
51
52            else{
53                f(node+offset,0);
54            }
55
56            //Check node-1
57            if(node-1 > 0 and nums[node-1] > nums[node-2] and nums[node-1] > nums[node]){
58                f(node+offset-1,1);
59            }
60
61            else{
62                f(node+offset-1,0);
63            }
64
65            //Check node+1
66            if(node+1 < nums.size()-1 and nums[node+1] > nums[node+2] and nums[node+1] > nums[node]){
67                f(node+offset+1,1);
68            }
69
70            else{
71                f(node+offset+1,0);
72            }
73        }
74    }
75
76    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
77        int n = nums.size();
78        int new_n = 1;
79        while(new_n < n){
80            new_n <<= 1;
81        }
82
83        vector<int> tree(2*new_n,0);
84        for(int i = new_n; i < new_n+n; i++){
85            if(i-new_n == 0 || i-new_n == n-1) continue;
86            tree[i] = int(nums[i-new_n-1] < nums[i-new_n] and nums[i-new_n] > nums[i-new_n+1]);
87        }
88
89        for(int i = new_n-1; i >= 1; i--){
90            tree[i] = tree[2*i] + tree[2*i + 1];
91        }
92
93        vector<int> ans;
94        for(auto query: queries){
95            if(query[0] == 1){
96                ans.push_back(Query(tree, 1, 0, new_n-1, query[1]+1, query[2]-1));
97            }else{
98                update(tree, nums, query[1], query[2], new_n);
99            }
100        }
101
102        return ans;
103    }
104};