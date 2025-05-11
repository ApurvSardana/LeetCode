class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; int ans = 0;

        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[i]<st.top()){
                st.pop();
            }
            
            if(st.empty() || nums[i]>st.top()){
                st.push(nums[i]);
                if(nums[i] != 0) ans++;
            }
        }

        return ans;
    }
};