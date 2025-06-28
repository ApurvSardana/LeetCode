class Solution {
public:
    struct comp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second;
        }
    };
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int, int>> nums2(n);
        for(int i = 0; i < n; i++){
            nums2[i] = {nums[i], i};
        }

        sort(nums2.begin(), nums2.end());
        reverse(nums2.begin(), nums2.end());
        sort(nums2.begin(), nums2.begin()+k, comp());

        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = nums2[i].first;
        }

        return ans;
    }
};