class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> f(101, 0);
        for(auto &num : nums) f[num]++;
        return count(f.begin(), f.end(), *max_element(f.begin(), f.end()))*(*max_element(f.begin(), f.end()));
    }
};