class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); int q = queries.size();

        vector<int> diff(n+1, 0), countOfIndex(n, 0);

        for(int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            diff[l]++; diff[r+1]--;
        }

        countOfIndex[0] = diff[0];
        for(int i = 1; i < n; i++)
            countOfIndex[i] = countOfIndex[i-1] + diff[i];

        for(int i = 0; i < n; i++)
            if(nums[i] > countOfIndex[i])
                return false;
        
        return true;
    }
};