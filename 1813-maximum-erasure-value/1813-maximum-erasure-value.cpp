class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        int l = 0, r = 0;
        int curr_sum = 0, max_sum = 0;
        while(r < n){
            if(!s.count(nums[r])){
                curr_sum += nums[r];
            }

            else{
                max_sum = max(max_sum, curr_sum);
                while(!s.empty() && s.count(nums[r])){
                    curr_sum -= nums[l];
                    s.erase(nums[l++]);
                }

                curr_sum += nums[r];
            }
            
            s.insert(nums[r++]);
        }

        max_sum = max(max_sum, curr_sum);
        return max_sum;
    }
};