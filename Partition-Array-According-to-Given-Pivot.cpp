class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans1;
        vector<int> ans2;
        vector<int> ans3;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)
                ans1.push_back(nums[i]);
            
            else if(nums[i] > pivot)
                ans3.push_back(nums[i]);
            
            else
                ans2.push_back(nums[i]);
        }

        vector<int> ans;
        for(int i : ans1)
            ans.push_back(i);

        for(int i : ans2)
            ans.push_back(i);

        for(int i : ans3)
            ans.push_back(i);

        return ans;

    }
};