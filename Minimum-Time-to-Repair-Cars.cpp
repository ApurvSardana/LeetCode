class Solution {
public:
    bool f(vector<int> &ranks, long long max_time, int totalCars){
        int n = ranks.size();
        int i = 0;
        long long cars_repaired = 0;
        long long time = 0;

        while(i < n && cars_repaired < totalCars){
            cars_repaired += sqrt((max_time / ranks[i]));
            i++;
        }

        return cars_repaired >= totalCars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        sort(ranks.begin(), ranks.end());

        long long l = 1;
        long long r = 1e14;

        while(l <= r){
            long long mid = l + (r-l)/2;
            if(f(ranks, mid, cars))
                r = mid-1;
            
            else
                l = mid+1;
        }
        return l;
    }
};