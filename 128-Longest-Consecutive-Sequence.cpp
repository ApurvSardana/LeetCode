class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());

        auto it = unique(nums.begin(), nums.end());
        nums.resize(it - nums.begin());

        int count = 1;
        int max_count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]+1)
                count++;
            
            else
                count = 1;
            
            max_count = max(max_count, count);
        }
        return max_count;
    }
};