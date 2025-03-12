class Solution {
public:
    int bsn(vector<int> &nums, int l, int r){
        if(l == r){
            if(nums[l] < 0)
                return l;
            
            return -1;
        }

        else if(r - l == 1){
            if(nums[r] < 0)
                return r;
            
            else if(nums[l] < 0)
                return l;
            
            return -1;
        }

        int mid = l + (r-l)/2;
        if(nums[mid] < 0)
            return bsn(nums, mid, r);
        
        else
            return bsn(nums, l, mid-1);        
    }

    int bsf(vector<int> &nums, int l, int r){
        if(l == r){
            if(nums[l] > 0)
                return l;
            
            return nums.size();
        }

        if(r - l == 1){
            if(nums[l] > 0)
                return l;
            
            else if(nums[r] > 0)
                return r;
            
            return nums.size();
        }

        int mid = l + (r-l)/2;
        if(nums[mid] > 0)
            return bsf(nums, l, mid);
        
        else
            return bsf(nums, mid+1, r);        
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int last_negative = bsn(nums, 0, n-1);

        int first_positive = bsf(nums, 0, n-1);

        return max(last_negative + 1, n - first_positive);
    }
};