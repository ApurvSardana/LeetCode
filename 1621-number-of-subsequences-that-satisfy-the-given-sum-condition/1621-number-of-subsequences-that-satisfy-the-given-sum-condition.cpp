class Solution {
public:
    int MOD = 1e9 + 7;
    long long modPow(long long a, long long b){
        if(b == 0) return 1;

        long long ans = modPow(a, b/2)%MOD;
        ans = ((ans%MOD)*(ans%MOD))%MOD;
        if(b&1){
            ans = ((ans%MOD)*(a%MOD))%MOD;
        }

        return ans%MOD;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        //cout << n << endl;
        sort(nums.begin(), nums.end());

        long long total = modPow(2, n);
        total = (total + MOD - 1)%MOD;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int j = upper_bound(nums.begin()+i, nums.end(), target-nums[i]) - nums.begin();
            if(j >= n) continue;

            if(j == i){
                ans++;
                j++;
            }

            long long a = modPow(2, j-i-1);
            long long rn = (modPow(2, n-j)%MOD);
            long long rn1 = (rn + MOD - 1)%MOD;
            long long term = (a*rn1)%MOD;
            //cout << i << " ; " << j << endl;
            ans = (ans+term)%MOD;
        }

        //cout << total << endl;
        return (total-ans + MOD)%MOD;
    }
};