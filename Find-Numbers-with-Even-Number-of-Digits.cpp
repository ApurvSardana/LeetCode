class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i : nums)
            ans += (to_string(i).length()%2 == 0);
        return ans;
    }
};