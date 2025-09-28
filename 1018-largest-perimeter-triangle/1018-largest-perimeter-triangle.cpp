class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());

        for(int i = 0; i+2 < n; i++){
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if(a+b>c && b+c>a && a+c>b)
                return a+b+c;
        }

        return 0;
    }
};