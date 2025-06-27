class Solution {
public:
    vector<vector<int>> ans;

    void f(vector<int> &candidates, vector<int> &curr, int target, int index){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(index >= candidates.size() || target < candidates[index]){
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(candidates[index] > target || (i > index && candidates[i] == candidates[i-1])){
                continue;
            }

            curr.push_back(candidates[i]);
            f(candidates, curr, target-candidates[i], i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        f(candidates, curr, target, 0);

        return ans;
    }
};