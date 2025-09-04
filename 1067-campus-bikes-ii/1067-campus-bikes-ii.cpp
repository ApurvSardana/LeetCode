class Solution {
public:
    int fact(int x){
        if(x == 0 || x == 1){
            return 1;
        }

        return x*fact(x-1);
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();

        int mf = fact(m);
        int min_dis = INT_MAX;
        for(int i = 0; i < mf; i++){
            next_permutation(bikes.begin(), bikes.end());

            int dis = 0;
            for(int index = 0; index < n; index++){
                dis += abs(workers[index][0]-bikes[index][0]) + abs(workers[index][1]-bikes[index][1]);
            }

            min_dis = min(min_dis, dis);
        }

        return min_dis;
    }
};