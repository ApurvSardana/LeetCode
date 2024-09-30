class Solution {
public:
    vector<int> nserF(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        stack<pair<int, int>> st;
        st.push({-1, arr.size()});

        for(int i = arr.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top().first >= arr[i])
            st.pop();
        
            if(!st.empty())
            ans[i] = st.top().second;

            st.push({arr[i], i});
        }

        return ans;

    }
    vector<int> nselF(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        stack<pair<int, int>> st;
        st.push({-1, -1});

        for(int i = 0; i < arr.size(); i++)
        {
            while(!st.empty() && st.top().first >= arr[i])
            st.pop();
        
            if(!st.empty())
            ans[i] = st.top().second;

            st.push({arr[i], i});
        }

        return ans;

    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> recArea(heights.size());
        int maxArea = INT_MIN;

        vector<int> nser = nserF(heights);

        vector<int> nsel = nselF(heights);

        for(int i = 0; i < heights.size(); i++)
        {
            recArea[i] = heights[i] * (nser[i] - nsel[i] - 1);
        }

        for(auto n : recArea)
        {
            if(n > maxArea) 
            maxArea = n;
        }

        return maxArea;
    }
};