1class FT{
2    public:
3    int n;
4    vector<int> tree;
5    FT(int n){
6        this->n = n;
7        tree.resize(n);
8    }
9
10    void update(int index){
11        while(index < n){
12            tree[index] += 1;
13            index += (index & (-index));
14        }
15    }
16
17    int query(int val){
18        int ans = 0;
19        while(val > 0){
20            ans += tree[val];
21            val -= (val & (-val));
22        }
23        return ans;
24    }
25};
26class Solution {
27public:
28    vector<int> countSmaller(vector<int>& nums) {
29        int n = nums.size();
30        for(int i = 0; i < n; i++)
31            nums[i] += 1e4+1;
32        
33        FT ft(2e4 + 2);
34        vector<int> count(n, 0);
35        for(int i = n-1; i >= 0; i--){
36            count[i] = ft.query(nums[i]-1);
37            ft.update(nums[i]);
38        }
39
40        return count;
41    }
42};