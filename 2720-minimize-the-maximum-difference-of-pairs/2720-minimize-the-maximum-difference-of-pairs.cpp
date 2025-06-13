class Solution {
public:
    bool f(vector<int> nums, int diff, int pairs){
        int count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(abs(nums[i]-nums[i+1]) <= diff){
                count++;
                i++;
            }
        }

        return count >= pairs;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0; int right = nums[n-1]-nums[0];
        while(left <= right){
            int mid = left + (right-left)/2;
            if(f(nums, mid, p)) right = mid-1;
            else left = mid+1;
        }

        return left;
    }
};