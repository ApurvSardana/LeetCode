class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map <int, int> m;
        int len = nums.size();
        vector <int> ans;

        for(int i = 0; i < len; i++)
        {
            m[nums[i]]++;
        }

        for(auto i : m)
        {
            if(i.second > len/3)
            ans.push_back(i.first);
        }
        return ans;
    }
};