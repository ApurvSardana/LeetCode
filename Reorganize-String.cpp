1class Solution {
2public:
3    string reorganizeString(string s) {
4        int n = s.length();
5        vector<int> f(26, 0);
6        for(auto ch : s) f[ch-'a']++;
7
8        if(*max_element(f.begin(), f.end()) > (n+1)/2) return "";
9
10        vector<pair<char, int>> v;
11        for(int i = 0; i < 26; i++){
12            if(f[i] != 0){
13                v.push_back({char('a'+i), f[i]});
14            }
15        }
16
17        sort(v.begin(),v.end(), [&](pair<char,int> &a, pair<char,int> &b){return a.second > b.second;});
18
19        string new_s(n, '?');
20        int ptr = 0, ptr2 = 0;
21        while(ptr < n && v[ptr2].second > 0){
22            while(ptr < n && v[ptr2].second > 0){
23                new_s[ptr] = v[ptr2].first;
24                ptr += 2;
25                v[ptr2].second--;
26            }
27
28            if(ptr >= n) break;
29            ptr2++;
30        }
31
32        // sort(v.begin(),v.end(), [&](pair<char,int> &a, pair<char,int> &b){return a.second > b.second;});
33        // cout << new_s << endl;
34        if(v[ptr2].second == 0) ptr2++;
35        ptr = 1;
36        while(ptr < n && v[ptr2].second > 0){
37            while(ptr < n && v[ptr2].second > 0){
38                new_s[ptr] = v[ptr2].first;
39                ptr += 2;
40                v[ptr2].second--;
41            }
42
43            if(ptr >= n) break;
44            ptr2++;
45        }
46
47        return new_s;
48    }
49};