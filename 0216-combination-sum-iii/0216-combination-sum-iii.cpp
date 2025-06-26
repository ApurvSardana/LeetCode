class Solution {
public:
    vector<vector<int>> ans;

    void f(vector<int> &nums, vector<int> &curr, int index, int target, int k){
        if(target == 0 && curr.size() == k){
            vector<int> temp = curr;
            ans.push_back(temp);
        }

        if(index >= nums.size() || target < nums[index]) return;

        f(nums, curr, index+1, target, k);
        curr.push_back(nums[index]);
        f(nums, curr, index+1, target-nums[index], k);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i <= 9; i++) nums.push_back(i);

        vector<int> curr = {};
        f(nums, curr, 0, n, k);

        return ans;
    }
};