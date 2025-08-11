class Solution {
public:
    int MOD = 1e9 + 7;
    long long pow_(long long a, long long b){
        if(b == 0) return 1;

        long long result = pow_(a, b/2);
        result = (result*result)%MOD;

        if(b%2)
            result = (result*a)%MOD;
        
        return result;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power_indices;

        for(int i = 0; i <= 31; i++){
            if(n & (1 << i))
                power_indices.push_back(i);
        }

        vector<int> ps;
        ps.push_back(0);

        for(int index : power_indices){
            ps.push_back(ps.back()+index);
        }

        vector<long long> ans;
        for(auto query : queries){
            int left = query[0], right = query[1];
            ans.push_back(pow_(2, ps[right+1]-ps[left]));
        }

        vector<int> ans2;
        for(auto num : ans)
            ans2.push_back((int)num);

        return ans2;
    }
};