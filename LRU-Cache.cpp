1class LRUCache {
2public:
3    int max_capacity, curr_capacity;
4    // unordered_map<int, int> cache;
5    vector<int> cache;
6    // unordered_map<int, int> accessedAt;
7    vector<int> accessedAt;
8    set<pair<int, int>> st;
9    int time, inf;
10    LRUCache(int capacity) {
11        max_capacity = capacity;
12        curr_capacity = 0;
13        cache.assign(1e4+1, -1);
14        accessedAt.assign(1e4+1, inf);
15        time = 0;
16        inf = 2e6;
17    }
18    
19    int get(int key) {
20        // cout << "Get " << key << " ->\n";
21        // cout << "BEFORE : \n";
22        // for(auto [k,v] : cache) cout << k << "," << v << " ";
23        // cout << endl;
24        // for(auto [k,t] : accessedAt) cout << k << "," << t << " ";
25        // cout << endl;
26        // for(auto [t,k] : st) cout << t << "," << k << " ";
27        // cout << endl;
28        if(cache[key] == -1) return -1;
29        st.erase({accessedAt[key],key});
30        accessedAt[key] = time++;
31        st.insert({accessedAt[key], key});
32        // cout << "AFTER : \n";
33        // for(auto [k,v] : cache) cout << k << "," << v << " ";
34        // cout << endl;
35        // for(auto [k,t] : accessedAt) cout << k << "," << t << " ";
36        // cout << endl;
37        // for(auto [t,k] : st) cout << t << "," << k << " ";
38        // cout << endl;
39        return cache[key];
40    }
41    
42    void put(int key, int value) {
43        // cout << "PUT " << key  << "," << value << " ->\n";
44        // cout << "BEFORE : \n";
45        // for(auto [k,v] : cache) cout << k << "," << v << " ";
46        // cout << endl;
47        // for(auto [k,t] : accessedAt) cout << k << "," << t << " ";
48        // cout << endl;
49        // for(auto [t,k] : st) cout << t << "," << k << " ";
50        // cout << endl;
51        if(cache[key] != -1){
52            st.erase({accessedAt[key],key});
53            cache[key] = value;
54            accessedAt[key] = time++;
55            st.insert({accessedAt[key],key});
56        }
57
58        else{
59            if(curr_capacity < max_capacity){
60                cache[key] = value;
61                accessedAt[key] = time++;
62                st.insert({accessedAt[key], key});
63                curr_capacity++;
64            }
65
66            else{
67                cache[(st.begin()->second)] = -1;
68                accessedAt[(st.begin()->second)] = inf;
69                st.erase(*st.begin());
70
71                cache[key] = value;
72                accessedAt[key] = time++;
73                st.insert({accessedAt[key], key});
74            }
75        }
76        // cout << "AFTER : \n";
77        // for(auto [k,v] : cache) cout << k << "," << v << " ";
78        // cout << endl;
79        // for(auto [k,t] : accessedAt) cout << k << "," << t << " ";
80        // cout << endl;
81        // for(auto [t,k] : st) cout << t << "," << k << " ";
82        // cout << endl;
83    }
84};
85
86/**
87 * Your LRUCache object will be instantiated and called as such:
88 * LRUCache* obj = new LRUCache(capacity);
89 * int param_1 = obj->get(key);
90 * obj->put(key,value);
91 */