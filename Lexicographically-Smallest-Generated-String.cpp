1class Solution {
2public:
3    string generateString(string str1, string str2) {
4        int n = str1.length(), m = str2.length();
5        // cout << n << endl;
6        // cout << m << endl;
7        // cout << n+m-1 << endl;
8        string s(n+m-1, 'A');
9        vector<bool> fixed(n+m-1, false);
10
11        //place chars where we dont have any choice
12        for(int i = 0; i < n; i++){
13            if(str1[i] == 'T'){
14                // cout << i << " -> \n";
15                int ptr = 0;
16                for(int j = i; j < i+m; j++){
17                    if(s[j] == 'A'){
18                        s[j] = str2[ptr];
19                        fixed[j] = true;
20                        ptr++;
21                    }
22
23                    else if(s[j] != str2[ptr]){
24                        return "";
25                    }
26
27                    else{
28                        // fixed[j] = true;
29                        ptr++;
30                    }
31
32                    // cout << s << endl;
33                }
34            }
35        }
36
37        // if(n+m-1 > 500)cout << fixed[500] << endl;
38        // cout << s << endl;
39
40        //Place 'a' where we have choice
41        for(int i = 0; i < n; i++){
42            if(str1[i] == 'F'){
43                for(int j = i; j < i+m; j++){
44                    if(!fixed[j]){
45                        s[j] = 'a';
46                    }
47                }
48            }
49        }
50
51        //Rectify your mistakes
52        for(int i = 0; i < n; i++){
53            if(str1[i] == 'F'){
54                bool ok = true;
55                int ptr = 0;
56                for(int j = i; j < i+m; j++){
57                    ok &= (s[j] == str2[ptr]);
58                    ptr++;
59                }
60
61                if(ok){
62                    // cout << i << endl;
63                    bool done = false;
64                    for(int j = i+m-1; j >= i; j--){
65                        //All the debugging statements are here,
66                        //because I was writing i, instead of j
67                        //in this fucking if statement. I'm an Asshole
68                        if(!fixed[j]){
69                            // s[j] = 'b';
70
71                            // if(str2[j-i] == 'a') s[j] = 'b';
72                            // else s[j] = 'a';
73                            s[j] = 'b';
74                            done = true;
75                            break;
76                        }
77                    }
78
79                    if(!done) return "";
80                }
81            }
82        }
83
84        // Verify
85        // for(int i = 0; i < n; i++){
86        //     bool ok = true; int ptr = 0;
87        //     for(int j = i; j < i+m; j++){
88        //         ok &= (s[j] == str2[ptr]);
89        //         ptr++;
90        //     }
91
92        //     if(str1[i] == 'T'){
93        //         if(!ok){
94        //             for(int i)
95        //         }
96        //     }
97        // }
98
99        return s;
100    }
101};