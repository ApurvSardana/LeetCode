class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(100001, 0);

        for(int i : nums)
            if(i >= 1 && i <= 100000)
                freq[i]++;
        
        for(int i = 1; i <= 100000; i++)
            if(freq[i] == 0)
                return i;
        
        return 100001;
    }
};