class Solution {
public:
    int water(vector<int> &height, int i, int &size)
    {
        int area = 0;
        int maxarea = 0;
        for(int k = size - 1; k > i; k--)
        {
            int shorter = min(height[k], height[i]);
            area = shorter * (k - i);

            maxarea = max(area, maxarea);

            if(shorter == height[i])
            return maxarea;
        }
        return maxarea;
    }
    int maxArea(vector<int>& height) {
        int size = height.size();

        int maxWater = 0;
        int ans = 0;
        for(int i = 0; i < size - 1; i++)
        {
            ans = water(height, i, size);
            maxWater = max(maxWater, ans);
        }

        return maxWater;
        
    }
};