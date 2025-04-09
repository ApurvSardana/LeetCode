class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        if(*min_element(nums.begin(), nums.end()) < k)
            return -1;
        
        set<int> s;
        for(int i : nums)
            if(i > k)
                s.insert(i);
        
        return s.size();
    }
};