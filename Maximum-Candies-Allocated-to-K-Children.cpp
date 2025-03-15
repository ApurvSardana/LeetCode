class Solution {
public:
    bool f(vector<int> &candies, long long k, long long m){
        int i = 0;
        while(k > 0 && i < candies.size()){
            int val = candies[i];
            k -= val/m;
            i++;
        }

        return k <= 0;
    }
    int bs(vector<int> &candies, long long k, long long l, long long r){
        while(l <= r){
            long long mid = l + (r-l)/2;

            if(f(candies, k, mid))
                l = mid+1;
            
            else
                r = mid-1;
        }
        return r;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);

        if(sum < k)
            return 0;

        sort(candies.begin(), candies.end());
        reverse(candies.begin(), candies.end());
    
        long long max_val = candies[0];

        int ans = bs(candies, k, 1, max_val);
        
        return ans;
    }
};