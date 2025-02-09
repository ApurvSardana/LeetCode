class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map <int, int> frequency;
        for(int i = 0; i < n; i++){
            nums[i] = nums[i] - i;
            frequency[nums[i]]++;
        }

        long long good_pairs = 0;
        for(auto p : frequency){
            if(p.second <= 1)
                continue;
            
            good_pairs += (long long)p.second*(p.second-1)/2;
        }

        ans = ((long long)n*(n-1)/2) - good_pairs;
        return ans;
    }
};