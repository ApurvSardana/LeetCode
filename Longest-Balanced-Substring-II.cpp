1class Solution {
2public:
3    int f1(string &s, int n, char ch){
4        int len = 0, max_len = 0;
5        for(int i = 0; i < n; i++){
6            if(s[i] == ch){
7                len++;
8            }
9
10            else{
11                len = 0;
12            }
13
14            max_len = max(max_len, len);
15        }
16
17        return max_len;
18    }
19
20    int f2(string &s, int n, char ch1, char ch2){
21        int max_len = 0;
22        map<int, int> mp;
23        int f1 = 0, f2 = 0;
24        mp[0] = -1;
25        for(int i = 0; i < n; i++){
26            if(s[i] == ch1) f1++;
27            else if(s[i] == ch2) f2++;
28            else{
29                mp.clear();
30                f1 = 0;
31                f2 = 0;
32                mp[0] = i;
33            }
34
35            if(mp.find(f2-f1) != mp.end()){
36                max_len = max(max_len, i-mp[f2-f1]);
37            }else{
38                mp[f2-f1] = i;
39            }
40        }
41
42        return max_len;
43    }
44
45    int f3(string &s, int n){
46        int f[3] = {0};
47        map<tuple<int, int, int>, int> mp;
48        int max_len = 0;
49        mp[{0,0,0}] = -1;
50        for(int i = 0; i < n; i++){
51            f[s[i]-'a']++;
52
53            if(mp.find({f[0]-f[1], f[1]-f[2], f[2]-f[0]}) != mp.end()){
54                max_len = max(max_len, i-mp[{f[0]-f[1], f[1]-f[2], f[2]-f[0]}]);
55            }else{
56                mp[{f[0]-f[1], f[1]-f[2], f[2]-f[0]}] = i;
57            }
58        }
59
60        return max_len;
61    }
62
63    int longestBalanced(string s) {
64        int n = s.length();
65
66        return max({
67            f1(s,n,'a'), f1(s,n,'b'), f1(s,n,'c'),
68            f2(s,n,'a','b'), f2(s,n,'b','c'), f2(s,n,'c','a'),
69            f3(s,n)
70        }); 
71    }
72};