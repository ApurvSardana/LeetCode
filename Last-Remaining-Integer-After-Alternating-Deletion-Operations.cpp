1class Solution {
2public:
3    using ll = long long;
4    long long lastInteger(long long n) {
5        ll a = 1, d = 1;
6        bool leftToRight = true;
7        while(n > 1){
8            if(leftToRight){
9                d *= 2;
10                n = (n+1)/2;
11            }
12
13            else{
14                if(n%2 == 0){
15                    a += d;
16                    d *= 2;
17                    n = (n+1)/2;
18                }
19
20                else{
21                    d *= 2;
22                    n = (n+1)/2;
23                }
24            }
25
26            leftToRight = !leftToRight;
27        }
28
29        return a;
30    }
31};