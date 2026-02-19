1class LUPrefix {
2public:
3    int n;
4    vector<int> tree;
5    int query(int node, int node_low, int node_high){
6        if(tree[node] == node_high-node_low+1){
7            return node_high-node_low+1;
8        }
9
10        int left = 0, right = 0, last_left = (node_low+node_high)/2;
11        if(2*node+1 < 2*n){
12            left = query(2*node, node_low, last_left);
13            if(left < last_left-node_low+1) return left;
14            right = query(2*node+1, last_left+1, node_high);
15        }
16        
17        return left + right;
18    }
19
20    LUPrefix(int n) {
21        while(__builtin_popcount(n) != 1) n++;
22        this->n = n;
23        tree.resize(2*n);
24    }
25    
26    void upload(int video) {
27        int node = video+n-1;
28        tree[node] = 1;
29        for(node = node/2; node >= 1; node /= 2){
30            tree[node] = tree[2*node] + tree[2*node+1];
31        }
32    }
33    
34    int longest() {
35        // cout << "Here -> \n";
36        // for(int i = 1; i < 2*n; i++){
37        //     cout << tree[i] << " ";
38        //     if(__builtin_popcount(i+1) == 1) cout << endl;
39        // }
40
41        // cout << endl;
42        return query(1, 0, n-1);
43    }
44};
45
46/**
47 * Your LUPrefix object will be instantiated and called as such:
48 * LUPrefix* obj = new LUPrefix(n);
49 * obj->upload(video);
50 * int param_2 = obj->longest();
51 */