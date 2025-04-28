class Solution {
public:
    long long bs(int l, int r, vector<long long> &ps, long long k){
        // if(ps[l] - ps[l-1] >= k)
        //     return 0;
        
        int orig_l = l;
        while(l <= r){
            int mid = l + (r-l)/2;

            if((ps[mid] - ps[orig_l-1])*(mid-orig_l+1) >= k)
                r = mid-1;
            
            else
                l = mid+1;
        }

        //cout << orig_l << " " << r << endl;
        return r;
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size(); long long ans = 0LL;
        vector<long long> ps(n+1, 0);

        for(int i = 0; i < n; i++)
            ps[i+1] = ps[i] + nums[i];
        
        for(int i = 1; i <= n; i++){
            //cout << bs(i, n, ps, k) << endl;
            ans += bs(i, n, ps, k) - i + 1;
        }
        return ans;
    }
};