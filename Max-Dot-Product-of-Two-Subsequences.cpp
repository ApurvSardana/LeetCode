1class Solution {
2public:
3    int f(vector<int> &nums1, vector<int> &nums2){
4        int n1 = nums1.size(), n2 = nums2.size();
5        bool all_neg1 = true, all_pos1 = true, all_neg2 = true, all_pos2 = true;
6        int mn1 = INT_MAX, mn2 = INT_MAX;
7        for(int i = 0; i < n1; i++){
8            all_neg1 &= (nums1[i]<0);
9            all_pos1 &= (nums1[i]>0);
10            mn1 = min(mn1, abs(nums1[i]));
11        }
12
13        for(int i = 0; i < n2; i++){
14            all_neg2 &= (nums2[i]<0);
15            all_pos2 &= (nums2[i]>0);
16            mn2 = min(mn2, abs(nums2[i]));
17        }
18
19        vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));
20        int ans = INT_MIN;
21
22        for(int i = 0; i <= n1; i++){
23            dp[i][0] = 0;
24        }
25
26        // dp[1][1] = nums1[0]*nums2[0];
27        for(int j = 1; j <= n2; j++){
28            for(int i = 1; i <= n1; i++){
29                dp[i][j] = dp[i-1][j];
30                for(int k = 1; k <= j; k++){
31                    dp[i][j] = max(dp[i][j], dp[i-1][k-1] + nums1[i-1]*nums2[k-1]);
32                    ans = max(ans, dp[i][j]);
33                }
34            }
35        }
36
37        // for(int i = 1; i <= n1; i++){
38        //     for(int j = 1; j <= n2; j++){
39        //         cout << i << "," << j << " : " << dp[i][j] << endl;
40        //     }
41        // }
42
43        // cout << endl;
44
45        if((all_neg1 && all_pos2) || (all_neg2 && all_pos1)){
46            return -mn1*mn2;
47        }
48        return ans;
49    }
50
51    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
52        return f(nums1,nums2);
53        // return max(f(nums1, nums2), f(nums2, nums1));
54    }
55};