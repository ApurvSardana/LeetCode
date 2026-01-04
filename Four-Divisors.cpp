1class Solution {
2public:
3    int sumFourDivisors(vector<int>& nums) {
4        int n = nums.size(), ans = 0;
5
6        function<int (int)> divisors_sum = [&](int x){
7            int sum = 1+x, divs = 2;
8            for(int i = 2; i*i <= x; i++){
9                divs += 2*(x%i == 0) - (x == i*i);
10                sum += (x%i == 0) ? i + x/i : 0;
11            }
12
13            return (divs == 4) ? sum : 0;
14        };
15        
16        for(int i = 0; i < n; i++){
17            int sum = divisors_sum(nums[i]);
18            ans += sum;
19        }   
20
21        return ans;
22    }
23};