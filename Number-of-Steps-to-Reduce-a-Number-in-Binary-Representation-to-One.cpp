1class Solution {
2public:
3    int numSteps(string s) {
4        int ans = 0;
5        while(s.length()){
6            if(s.back() == '0'){
7                s.pop_back();
8                ans++;
9            }else{
10                if(s.length() == 1) return ans;
11                
12                ans++;
13                int ptr = s.length()-1;
14                while(ptr >= 0 && s[ptr] == '1') s[ptr--] = '0';
15
16                if(ptr == -1) return ans + s.length();
17                else s[ptr] = '1';
18            }
19        }
20        return ans;
21    }
22};