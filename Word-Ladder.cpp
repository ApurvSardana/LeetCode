1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
4        unordered_map<string, set<string>> adj;
5        unordered_set<string> vis;
6        adj[beginWord] = {};
7        int n = wordList.size();
8
9        auto isMatching = [&](string &a, string &b) -> bool{
10            int count = 0;
11            for(int i = 0; i < a.length(); i++){
12                count += (a[i] != b[i]);
13            }
14
15            return count == 1;
16        };
17
18        for(int i = 0; i < n; i++){
19            if(wordList[i] == beginWord) continue;
20            if(isMatching(beginWord, wordList[i])){
21                adj[beginWord].insert(wordList[i]);
22                adj[wordList[i]].insert(beginWord);
23            }
24        }
25
26        for(int i = 0; i < n; i++){
27            if(wordList[i] == beginWord) continue;
28            for(int j = i+1; j < n; j++){
29                if(wordList[j] == beginWord) continue;
30                if(isMatching(wordList[i], wordList[j])){
31                    adj[wordList[i]].insert(wordList[j]);
32                    adj[wordList[j]].insert(wordList[i]);
33                }
34            }
35        }
36
37        queue<string> q;
38        q.push(beginWord);
39        q.push("!");
40        int level = 0;
41        while(!q.empty()){
42            string u = q.front();
43            q.pop();
44            if(u == endWord){
45                return level+1;
46            }
47
48            vis.insert(u);
49
50            if(u != "!"){
51                for(auto v : adj[u]){
52                    if(vis.find(v) == vis.end()){
53                        vis.insert(v);
54                        q.push(v);
55                    }
56                }
57            }
58
59            else{
60                level++;
61                if(!q.empty()){
62                    q.push("!");
63                }
64            }
65        }
66
67        return 0;
68    }
69};