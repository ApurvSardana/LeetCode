class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> one(1001, false);
        vector<bool> two(1001, false);

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++)
            one[nums1[i]] = true;

        for(int i = 0; i < nums2.size(); i++)
            two[nums2[i]] = true;
        
        for(int i = 0; i < 1001; i++)
            if(one[i] == true && two[i] == true)
                ans.push_back(i);

        return ans;
    }
};