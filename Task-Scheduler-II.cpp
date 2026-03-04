1class Solution {
2public:
3    using ll = long long;
4    long long taskSchedulerII(vector<int>& tasks, int space) {
5        int n = tasks.size();
6        unordered_map<int,ll> mp;
7        ll days = 0LL;
8        for(auto task : tasks){
9            if(mp.find(task) == mp.end()){
10                mp[task] = days;
11                days++;
12            }
13
14            else if(days-mp[task] >= space+1){
15                mp[task] = days;
16                days++;
17            }
18
19            else{
20                days = mp[task] + space + 1;
21                mp[task] = days;
22                days++;
23            }
24        }
25
26        return days;
27    }
28};