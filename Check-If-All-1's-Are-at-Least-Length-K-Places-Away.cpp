class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> ind;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) ind.push_back(i);
        }

        if(nums.size() <= 1) return true;

        for(int i = 1; i < ind.size(); i++){
            if(ind[i]-ind[i-1]-1 < k) return false;
        }

        return true;
    }
};