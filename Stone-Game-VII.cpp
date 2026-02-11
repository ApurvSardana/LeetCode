1class Solution {
2public:
3    int dpa[1000][1000], dpb[1000][1000];
4    int f(vector<int> &stones, vector<int> &ps, int l, int r, bool alice){
5        if(l >= r) return 0;
6        if(l == r) return alice ? stones[l] : -stones[l];
7        
8        if(alice && dpa[l][r] != -1e9) return dpa[l][r];
9        if(!alice && dpb[l][r] != 1e9) return dpb[l][r];
10
11        if(alice) return dpa[l][r] = max(ps[r+1]-ps[l+1]+f(stones,ps,l+1,r,false)
12                                        ,ps[r]-ps[l]+f(stones,ps,l,r-1,false));
13
14        else return dpb[l][r] = min(-ps[r+1]+ps[l+1]+f(stones,ps,l+1,r,true)
15                                   ,-ps[r]+ps[l]+f(stones,ps,l,r-1,true));
16    }
17    int stoneGameVII(vector<int>& stones) {
18        int n = stones.size();
19        for(int i = 0; i < 1000; i++){
20            for(int j = i; j < n; j++){
21                dpa[i][j] = -1e9;
22                dpb[i][j] = 1e9;
23            }
24        }
25
26        vector<int> ps(n+1,0);
27        for(int i = 0; i < n; i++) ps[i+1] = ps[i] + stones[i];
28
29        return f(stones, ps, 0, n-1, true);
30    }
31};