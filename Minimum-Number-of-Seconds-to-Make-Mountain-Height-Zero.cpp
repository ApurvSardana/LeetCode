1class Solution {
2public:
3    using ll = long long;
4    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
5        ll left = 1, right = 1e18;
6        auto f = [&](ll t, ll x) -> ll{
7            ll left = 0LL, right = mountainHeight;
8            while(left <= right){
9                ll k = left + ((right-left)>>1LL);
10
11                if((t*k*(k+1))/2 <= x) left = k+1;
12                else right = k-1;
13            }
14
15            return right;
16        };
17
18        while(left <= right){
19            ll mid = left + ((right-left)>>1LL);
20
21            ll height_reduced = 0LL;
22            for(auto time: workerTimes){
23                height_reduced += f(time, mid);
24                if(height_reduced >= mountainHeight) break;
25            }
26
27            if(height_reduced >= mountainHeight) right = mid-1;
28            else left = mid+1;
29        }
30
31        return left;
32    }
33};
34
35// (t*k*(k+1))/2 <= x
36// t*k*(k+1) <= 2*x
37// k^2 + k - 2*x/t <= 0;