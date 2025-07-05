class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        map<int, int> f;

        for(auto num : arr) f[num]++;

        int ans = -1;
        for(auto p : f){
            if(p.first == p.second) ans = p.first;
        }

        return ans;
    }
};