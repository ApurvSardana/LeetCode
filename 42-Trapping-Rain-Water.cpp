class Solution {
public:
    int trap(vector<int>& height) {

        int ans = 0;

        vector<int> max_right(height.size());
        vector<int> max_left(height.size());


        stack<int> stl;
        stack<int> str;

        stl.push(height[0]);
        str.push(height[height.size() - 1]);

        max_right[height.size() - 1] = 0;
        max_left[0] = 0;

        for(int i = 1; i < height.size(); i++)
        {
            if(stl.top() > height[i])
            max_left[i] = stl.top();

            else
            {
                max_left[i] = 0;
                stl.push(height[i]);
            } 
        }

        for(int i = height.size() - 2; i >= 0; i--)
        {
            if(str.top() > height[i])
            max_right[i] = str.top();

            else
            {
                max_right[i] = 0;
                str.push(height[i]);
            } 
        }

        for(int i = 0; i < height.size(); i++)
        {
            int water = min(max_left[i], max_right[i]) - height[i];

            if(water > 0)
            ans += water;
        }

        return ans;
    }
};