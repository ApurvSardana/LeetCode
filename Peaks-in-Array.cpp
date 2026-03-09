1class Solution {
2public:
3    int Query(vector<int>& tree, int node, int node_low, int node_high,
4              int query_low, int query_high) {
5        if (node_low > query_high or node_high < query_low)
6            return 0;
7
8        if (node_low >= query_low and query_high >= node_high) {
9            return tree[node];
10        }
11
12        int last_left = (node_low + node_high) / 2;
13        return Query(tree, 2 * node, node_low, last_left, query_low,
14                     query_high) +
15               Query(tree, 2 * node + 1, last_left + 1, node_high, query_low,
16                     query_high);
17    }
18
19    void update(vector<int>& tree, vector<int>& nums, int node, int val,
20                int offset) {
21        nums[node] = val;
22        auto f = [&](int a_node, int v) -> void {
23            tree[a_node] = v;
24            a_node /= 2;
25            while (a_node >= 1) {
26                tree[a_node] = tree[2 * a_node] + tree[2 * a_node + 1];
27                a_node /= 2;
28            }
29        };
30
31        // Check node
32        if (node > 0 and node < nums.size() - 1 and
33            nums[node] > nums[node - 1] and nums[node] > nums[node + 1]) {
34            f(node + offset, 1);
35        }
36
37        else {
38            f(node + offset, 0);
39        }
40
41        // Check node-1
42        if (node - 1 > 0 and nums[node - 1] > nums[node - 2] and
43            nums[node - 1] > nums[node]) {
44            f(node + offset - 1, 1);
45        }
46
47        else {
48            if(node-1 >= 0) f(node + offset - 1, 0);
49        }
50
51        // Check node+1
52        if (node + 1 < nums.size() - 1 and nums[node + 1] > nums[node + 2] and
53            nums[node + 1] > nums[node]) {
54            f(node + offset + 1, 1);
55        }
56
57        else {
58            if(node+1 < nums.size()) f(node + offset + 1, 0);
59        }
60    }
61
62    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
63        int n = nums.size();
64        int new_n = 1;
65        while (new_n < n) {
66            new_n <<= 1;
67        }
68
69        vector<int> tree(2 * new_n, 0);
70        for (int i = new_n; i < new_n + n; i++) {
71            if (i - new_n == 0 || i - new_n == n - 1)
72                continue;
73            tree[i] = int(nums[i - new_n - 1] < nums[i - new_n] and
74                          nums[i - new_n] > nums[i - new_n + 1]);
75        }
76
77        for (int i = new_n - 1; i >= 1; i--) {
78            tree[i] = tree[2 * i] + tree[2 * i + 1];
79        }
80
81        vector<int> ans;
82        for (auto query : queries) {
83            if (query[0] == 1) {
84                ans.push_back(
85                    Query(tree, 1, 0, new_n - 1, query[1] + 1, query[2] - 1));
86            } else {
87                update(tree, nums, query[1], query[2], new_n);
88            }
89        }
90
91        return ans;
92    }
93};