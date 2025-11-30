1class Solution {
2public:
3    using ll = long long;
4    int minSubarray(vector<int>& nums, int p) {
5        ll n = nums.size();
6        ll sum = accumulate(nums.begin(), nums.end(), 0LL)%p;
7
8        if(sum == 0) return 0;
9
10        vector<ll> ps(n+1, 0);
11        for(int i = 0; i < n; i++){
12            if(nums[i]%p == sum) return 1;
13            ps[i+1] = ps[i] + nums[i];
14            cout << ps[i+1] << " ";
15        }
16
17        // cout << endl;
18
19        // cout << sum << endl;
20
21        map<ll, ll> mp;
22        ll ans = INT_MAX;
23        for(ll i = 0; i <= n; i++){
24            if(!mp.empty() && mp.find(((ps[i]%p) + p - sum) % p) != mp.end()){
25                cout << i << ", " << mp[(((ps[i]%p) - sum + p)%p)] << endl;
26                ans = min(ans, i-mp[(((ps[i]%p) - sum + p)%p)]);
27            }
28
29            mp[ps[i]%p] = i;
30        }
31
32        return (ans >= n) ? -1 : ans;
33    }
34};