class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        this -> arr = nums;
    }
    
    int pick(int target) {
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == target)
            ans.push_back(i);
        }

        int x = rand() % (ans.size());

        return ans[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */