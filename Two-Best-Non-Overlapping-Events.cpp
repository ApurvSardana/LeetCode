1class Solution {
2public:
3    int bs(vector<vector<int>> &events, int target){
4        int n = events.size();
5        int left = 0, right = n-1;
6        while(left <= right){
7            int mid = left + (right-left)/2;
8            if(events[mid][0] > target)
9                right = mid-1;
10            
11            else left = mid+1;
12        }
13
14        return left;
15    }
16    int maxTwoEvents(vector<vector<int>>& events) {
17        int n = events.size();
18
19        sort(events.begin(), events.end());
20        int sum = events.back()[2];
21        vector<int> sm(n, events.back()[2]);
22        for(int i = n-2; i >= 0; i--){
23            sum = max(sum, events[i][2]);
24            sm[i] = max(events[i][2], sm[i+1]);
25        }
26
27        for(int i = 0; i < n; i++){
28            int j = bs(events, events[i][1]);
29            if(j < n) sum = max(sum, events[i][2] + sm[j]);
30        }
31
32        return sum;
33    }
34};