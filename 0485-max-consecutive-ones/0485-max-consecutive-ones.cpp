class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size()+1;
        nums.push_back(0);
        int i = 0; int j = 0; int curr_length = 0; int ans = 0;
        while(i < n && j < n){
            if(nums[j] == 0){
                ans = max(ans, curr_length);
                curr_length = 0;
                i = j+1;
            }

            else{
                curr_length++;
            }

            j++;
        }

        return ans;
    }
};