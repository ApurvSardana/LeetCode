class Solution {
public:
    set<vector<int>> s;
    void f(vector<int> &nums, vector<int> curr, int index, int n){
        if(index == n){
            s.insert(curr);
            return;
        }
        f(nums, curr, index+1, n);
        curr.push_back(nums[index]);
        f(nums, curr, index+1, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        f(nums, {}, 0, n);

        vector<vector<int>> ans;
        for(auto it : s) ans.push_back(it);

        return ans;
    }
};