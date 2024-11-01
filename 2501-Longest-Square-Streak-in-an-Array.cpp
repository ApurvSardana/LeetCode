class Solution {
public:
    int binSearch(vector<int> &nums, long long &target, int l, int r)
    {
        while(l <= r)
        {
            int mid = (l + r) / 2;

            if(nums[mid] == target)
            return mid;

            else if(nums[mid] < target)
            l = mid + 1;

            else
            r = mid - 1;
        }

        return -1;
    }
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();

        int maxLen = -1;

        set<int> s;

        for(int i = 0; i < size - 1; ++i)
        {
            int ans = 0;

            if(find(s.begin(), s.end(), nums[i]) != s.end())
            continue;

            long long temp = (long long)nums[i]*nums[i];
            int l = i + 1;
            int r = size - 1;
            while(binSearch(nums, temp, l, r) != -1)
            {
                s.insert(temp);
                ans++;
                temp = temp*temp;
            }
            if(ans != 0)
            maxLen = max(ans + 1, maxLen);
        }

        return maxLen;
    }
};