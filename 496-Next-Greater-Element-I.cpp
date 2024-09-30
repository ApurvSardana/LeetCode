class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> m;
        stack<int> st;

        st.push(nums2[nums2.size() - 1]);
        m[nums2[nums2.size() - 1]] = -1;

        for(int i = nums2.size() - 2; i >=0; i--)
        {
            
                while(!st.empty() && st.top() <= nums2[i])
                st.pop();

                if(!st.empty())
                {
                    m[nums2[i]] = st.top();
                }

                else
                m[nums2[i]] = -1;

                st.push(nums2[i]);
        }

        for(auto n : nums1)
        {
            ans.push_back(m[n]);
        }

        return ans;
    }
};