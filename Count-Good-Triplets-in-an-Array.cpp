1class Solution {
2public:
3    using ll = long long;
4    ll query(vector<ll>& tree, ll node, ll node_low, ll node_high, ll query_low,
5             ll query_high) {
6        if (node_low >= query_low && node_high <= query_high) {
7            return tree[node];
8        }
9
10        if (query_low > node_high || query_high < node_low)
11            return 0;
12
13        ll last_left = (node_low + node_high) / 2LL;
14        return query(tree, 2LL * node, node_low, last_left, query_low,
15                     query_high) +
16               query(tree, 2LL * node + 1, last_left + 1, node_high, query_low,
17                     query_high);
18    }
19
20    void update(vector<ll>& tree, ll node) {
21        tree[node] = 1;
22        node /= 2LL;
23        for (; node >= 1; node /= 2LL) {
24            tree[node] = tree[2LL * node] + tree[2LL * node + 1];
25        }
26    }
27
28    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
29        ll n = nums1.size();
30        ll orig_n = n;
31        vector<ll> p1(n), p2(n);
32        for (ll i = 0; i < n; i++) {
33            p1[nums1[i]] = i;
34            p2[nums2[i]] = i;
35        }
36
37        while (__builtin_popcountll(n) != 1)
38            n++;
39        
40        vector<ll> tree1(2 * n), tree2(2 * n), intersection_left(orig_n), intersection_right(n);
41
42        for (ll i = 0; i < orig_n; i++) {
43            ll pos = p2[nums1[i]];
44            intersection_left[i] = query(tree1, 1, 0, n - 1, 0, pos - 1);
45            update(tree1, pos + n);
46        }
47
48        for (ll i = orig_n - 1; i >= 0; i--) {
49            ll pos = p2[nums1[i]];
50            intersection_right[i] = query(tree2, 1, 0, n - 1, pos + 1, n - 1);
51            update(tree2, pos + n);
52        }
53
54        ll ans = 0LL;
55        for (ll i = 0; i < orig_n; i++) {
56            ans += intersection_left[i] * intersection_right[i];
57        }
58
59        return ans;
60    }
61};