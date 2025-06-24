class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            bool flag = false;
            for(int j = i-1; j >= 0 && i-k <= j; j--){
                if(nums[j] == key){
                    flag = true;
                    break;
                }
            }

            if(!flag)
                for(int j = i; j < n && j <= k+i; j++){
                    if(nums[j] == key){
                        flag = true;
                        break;
                    }
                }
            
            if(flag) ans.push_back(i);
        }

        return ans;
    }
};