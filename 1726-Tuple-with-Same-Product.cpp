class Solution {
public:
    long long F(int n){
        if(n == 1 || n == 0)
            return 1;
        
        return n*F(n-1);
    }
    long long C(int n, int r){
        long long nf = F(n);
        long long rf = F(r);
        long long nrf = F(n-r);

        return nf/(rf*nrf);
    }
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                m[nums[i]*nums[j]]++;
        
        long long ans = 0;
        for(auto i : m)
            if(i.second > 1)
                ans += C(i.second, 2);
        
        return (int)8*ans;
    }
};