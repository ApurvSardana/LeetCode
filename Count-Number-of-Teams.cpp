1class FT{
2public:
3    int n;
4    vector<int> tree;
5
6    FT(){
7        n = 1e5;
8        tree.assign(n+1,0);
9    }
10
11    void update(int val){
12        while(val <= n){
13            tree[val] += 1;
14            val += (val & (-val));
15        }
16    }
17
18    int query_less(int val){
19        int ans = 0;
20        while(val > 0){
21            ans += tree[val];
22            val -= (val & (-val));
23        }
24        return ans;
25    }
26};
27class Solution {
28public:
29    int numTeams(vector<int>& rating) {
30        int n = rating.size();
31        FT ft1, ft2;
32
33        vector<int> right_more(n,0), right_less(n,0), left_more(n,0), left_less(n,0);
34
35        for(int i = n-1; i >= 0; i--){
36            right_more[i] = ft1.query_less(1e5) - ft1.query_less(rating[i]);
37            right_less[i] = ft1.query_less(rating[i]-1);
38            ft1.update(rating[i]);
39        }
40
41        for(int i = 0; i < n; i++){
42            left_more[i] = ft2.query_less(1e5) - ft2.query_less(rating[i]);
43            left_less[i] = ft2.query_less(rating[i]-1);
44            ft2.update(rating[i]);
45        }
46
47        int ans = 0;
48        for(int i = 0; i < n; i++){
49            ans += left_less[i]*right_more[i] + left_more[i]*right_less[i];
50        }
51
52        return ans;
53    }
54};