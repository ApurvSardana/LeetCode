1class Solution {
2public:
3    vector<int> factors(int x){
4        vector<int> ans;
5        for(int i = 1; i*i <= x; i++){
6            if(x%i == 0){
7                ans.push_back(i);
8                if(i*i != x) ans.push_back(x/i);
9            }
10        }
11        return ans;
12    }
13
14    bool check(int k, vector<int> &nums){
15        int n = nums.size();
16
17        int last = -1;
18        for(int start = 0; start < n; start += k){
19            int mx = -1, mn = 1e9, inv = 0;
20            for(int i = start; i < start+k; i++){
21                mx = max(mx, nums[i]);
22                mn = min(mn, nums[i]);
23                if(i != start) inv += (nums[i] < nums[i-1]);
24            }
25
26            inv += (nums[start+k-1] > nums[start]);
27            if(mn < last or inv > 1) return false;
28            last = mx;
29        }
30
31        return true;
32    }
33    
34    int sortableIntegers(vector<int>& nums) {
35        int n = nums.size();
36        vector<int> divs = factors(n);
37
38        int sum = 0;
39        for(auto div: divs){
40            if(check(div,nums)){
41                // cout << div << endl;
42                sum += div;
43            }
44        }
45
46        return sum;
47    }
48};