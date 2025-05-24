class Solution {
public:
    void populate(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> curr_subset, int index){
        if(target == 0){
            ans.push_back(curr_subset);
            return;
        }

        else if(target < 0 || index >= candidates.size()){
            return;
        }

        else if(target > 0 && candidates[index] > target){
            return;
        }

        else if(target > 0 && candidates[index] <= target){
            populate(candidates, target, ans, curr_subset, index+1);
            curr_subset.push_back(candidates[index]);
            populate(candidates, target-candidates[index], ans, curr_subset, index);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr_subset;

        populate(candidates, target, ans, curr_subset, 0);

        return ans;
    }
};