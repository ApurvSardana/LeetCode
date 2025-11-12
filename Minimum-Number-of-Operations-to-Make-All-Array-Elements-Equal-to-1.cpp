class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            count += (nums[i] == 1);
        }

        if(count == 0){
            for(int len = 2; len <= n; len++){
                for(int i = 0; i+len-1 < n; i++){
                    int g = nums[i];
                    for(int j = i; j-i+1 <= len; j++){
                        g = __gcd(g, nums[j]);
                    }

                    if(g == 1){
                        return n+len-2;
                    }
                }
            }

            return -1;            
        }

        return n-count;
    }
};