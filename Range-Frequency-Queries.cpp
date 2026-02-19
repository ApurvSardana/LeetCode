1class RangeFreqQuery {
2public:
3    int n;
4    map<int, int> *tree;
5    int Q(int node, int node_low, int node_high, int left, int right, int value){
6        if(left <= node_low && node_high <= right){
7            return tree[node][value];
8        }
9    
10        if(node_high < left || node_low > right){
11            return 0;
12        }
13
14        int last_left = (node_high+node_low)/2;
15        return Q(2*node, node_low, last_left, left, right, value)
16              +Q(2*node+1, last_left+1, node_high, left, right, value);
17    }
18
19    RangeFreqQuery(vector<int> arr) {
20        n = arr.size();
21        while(__builtin_popcount(n) != 1){
22            arr.push_back(0);
23            n++;
24        }
25
26        //Build Tree
27        tree = new map<int, int>[2*n];
28        for(int i = n; i < 2*n; i++){
29            tree[i][arr[i-n]]++;
30        }
31
32        for(int i = n-1; i >= 1; i--){
33            for(auto &[v,f] : tree[2*i]) tree[i][v] += f;
34            for(auto &[v,f] : tree[2*i+1]) tree[i][v] += f;
35        }
36    }
37    
38    int query(int left, int right, int value) {
39        return Q(1, 0, n-1, left, right, value);
40    }
41};
42
43/**
44 * Your RangeFreqQuery object will be instantiated and called as such:
45 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
46 * int param_1 = obj->query(left,right,value);
47 */