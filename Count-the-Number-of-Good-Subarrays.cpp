class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(); long long count = 0;
        unordered_map<int, int> freq;

        int l = 0; int r = 0;
        long long pairs = 0;

        while(l < n && r < n){
            while(r < n && pairs < k){
                freq[nums[r]]++;
                pairs += freq[nums[r]] - 1;

                if(pairs >= k)
                    break;
                
                r++;
            }

            if(pairs >= k)
                count += n-r;
            
            else
                break;
            
            while(l <= r && pairs >= k){
                freq[nums[l]]--;
                pairs -= freq[nums[l]];
                l++;

                if(pairs >= k)
                    count += n-r;
                else
                    break;
            }
            r++;
        }
        return count;
    }
};