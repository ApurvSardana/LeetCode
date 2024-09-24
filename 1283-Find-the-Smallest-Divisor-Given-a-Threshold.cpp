class Solution {
public:

    bool check(vector<int> &nums, int x, int threshold)
    {
        long long sum = 0;
        for(int i : nums)
        {
            sum += ceil((double)i/x);
        }
        if(sum <= threshold) return true;

        else return false;
    }
    int bs(vector<int> &nums,int l, int r, int threshold)
    {
        
        while(l <= r)
        {
            if(l == r)
            return l;
            int mid = (l + r) / 2;
            // if(l == r)
            // return l;
                if(check(nums, mid, threshold))
                {
                    r = mid;
                }

                else
                l = mid + 1;
            }
            // return l;
            return l;
        }

       
    

    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = nums[0];
        for(int i : nums)
        if(i > max) 
        max = i;

        return bs(nums, 1, max, threshold);
    }
};