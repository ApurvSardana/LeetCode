class Solution {
public:

    int bsl(vector<int>& nums, int l, int r, int target)
    {
        int ans;

        if(l > r) return -1;

        // if(l == r)
        // return l;

        int mid = (l + r) / 2;

        if(nums[mid] == target)
        {
            if(mid == l || nums[mid - 1] != target)
            return mid;

        return bsl(nums, l, mid - 1, target);
        }

        else if(nums[mid] < target)
        {
            return bsl(nums, mid + 1, r, target);
            
        }

        else
        {
            return bsl(nums, l, mid - 1, target);
            
        }

        
    }

    int bsr(vector<int>& nums, int l, int r, int target)
    {
        int ans;

        if(l > r)
        return -1;

        // if (l == r)
        // return r;

        int mid = (l + r) / 2;

        if(nums[mid] == target)
        {
            if(mid == r || nums[mid + 1] != target)
            return mid;

        return bsr(nums, mid + 1, r, target);
        }

        else if(nums[mid] < target)
        {
            return bsr(nums, mid + 1, r, target);
        }

        else
        {
            return bsr(nums, l, mid - 1, target);
        }

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = bsl(nums, 0, nums.size() - 1, target);

        if(ans[0] != -1)
        ans[1] = bsr(nums, 0, nums.size() - 1, target);

        else return {-1, -1};

        return ans;
        
    }
};