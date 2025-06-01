class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        pair<int, int> p; int md = INT_MAX;
        p = {-1,-1};
        for(int i = n-1; i > 0; i--){
            for(int j = i-1; j >= 0; j--){
                if(nums[i] > nums[j] && (j > p.first || (j == p.first && nums[i]-nums[j] <= md))){
                    p = make_pair(j, i);
                    md = nums[i]-nums[j];
                }
            }
        }
        
        if(md == INT_MAX) sort(nums.begin(), nums.end());
        else{
            swap(nums[p.first], nums[p.second]);
            sort(nums.begin()+p.first+1, nums.end());
        }
    }
};