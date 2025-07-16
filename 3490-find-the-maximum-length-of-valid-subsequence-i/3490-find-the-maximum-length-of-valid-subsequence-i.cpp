class Solution {
public:
    int calculate_oe(vector<int> &nums, int &n){
        bool flag = true;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(flag && (nums[i]&1)){
                ans++;
                flag = !flag;
            }

            else if(!flag && !(nums[i]&1)){
                ans++;
                flag = !flag;
            }
        }

        return ans;
    }

    int calculate_eo(vector<int> &nums, int &n){
        bool flag = true;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(flag && !(nums[i]&1)){
                ans++;
                flag = !flag;
            }

            else if(!flag && (nums[i]&1)){
                ans++;
                flag = !flag;
            }
        }

        return ans;
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int onlyOdd = 0, onlyEven = 0, oddEven = 0, evenOdd = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]&1) onlyOdd++;
            else onlyEven++;
        }

        oddEven = calculate_oe(nums, n);
        evenOdd = calculate_eo(nums, n);

        return max(max(onlyOdd, onlyEven), max(oddEven, evenOdd));
    }
};