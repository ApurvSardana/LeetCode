class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if(k == 0) return ans;

        if(k < 0)
            reverse(code.begin(), code.end());

        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = 0; j < abs(k); j++)
                sum += code[(i + j + 1) % n];
            ans[i] = sum;
        }

        if(k < 0)
        reverse(ans.begin(), ans.end());

        return ans;
    }
};