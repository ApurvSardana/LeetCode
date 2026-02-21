1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n = height.size();
5        vector<int> sm(n,height[n-1]), pm(n,height[0]);
6
7        for(int i = 1; i < n; i++) pm[i] = max(pm[i-1], height[i]);
8        for(int i = n-2; i >= 0; i--) sm[i] = max(sm[i+1],height[i]);
9
10        int ans = 0;
11        for(int i = 1; i < int(height.size())-1; i++){
12            ans += max(0, min(sm[i+1], pm[i-1])-height[i]);
13        }
14        return ans;
15    }
16};