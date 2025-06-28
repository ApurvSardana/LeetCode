class Solution {
public:
    vector<vector<int>> ans; int N;
    void f(vector<int> &nums, vector<int> &curr, vector<bool> &taken){
        if(curr.size() == N){
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0; i < N; i++){
            if(taken[i]) continue;
            curr.push_back(nums[i]);
            taken[i] = true;

            f(nums, curr, taken);

            curr.pop_back();
            taken[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size(); N = n;

        vector<int> curr; vector<bool> taken(n, false);

        f(nums, curr, taken);
        
        return ans;
    }
};