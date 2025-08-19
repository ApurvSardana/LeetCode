class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0; int j = 0;
        long long ans = 0;
        while(j < n){
            if(nums[j] != 0){
                i++;
                j++;
            }

            else{
                while(j < n && nums[j] == 0){
                    j++;
                }
                long long N = j-i;
                //cout << N << endl;
                ans += ((N*(N+1))/2);
                i = j;
            }
        }

        return ans;
    }
};