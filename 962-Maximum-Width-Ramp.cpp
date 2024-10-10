class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> saar;
        vector<int> ans(nums.size());
        int a = INT_MIN;
        int s = nums.size();
        stack<pair<int, int>> st;

        for(int i = 0; i < s; i++)
        {
            saar.push_back({nums[i], i});
            st.push({nums[i], i});
        }

        

        // for(int i = 0; i < s; i++)
        // {
        //     st.push({nums[i], i});
        // }

        // while(!st.empty())
        // {
        //     cout << st.top().first << "," << st.top().second << " ";
        //     st.pop();
        // }

        sort(saar.begin(), saar.end());

        // for(int i = 0; i < saar.size(); i++)
        // {
        //     cout << saar[i].first << "," << saar[i].second << " ";
        // }

        for(int i = 0; i < s; i++)
        {
            if(saar[i].first <= st.top().first)
            
            {
                ans[saar[i].second] = st.top().second - saar[i].second;
            }
            else
            {
                st.pop();
                i--;
            }
        }

        for(int i = 0; i < s; i++)
        {
            // cout << ans[i] << " ";
            if(ans[i] >= a)
            a = ans[i];
        }

        return a;
    }
};