class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            st.push(nums[i]);
        }

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            st.pop();

            if(!st.empty())
            ans[i] = st.top();

            else ans[i] = -1;

            st.push(nums[i]);
        }
        return ans;
    }
};