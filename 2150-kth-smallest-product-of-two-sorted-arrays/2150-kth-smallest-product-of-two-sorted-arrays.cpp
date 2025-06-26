class Solution {
public:
    long long f(vector<int> &nums2, long long x, long long v){
        int n2 = nums2.size();
        int left = 0, right = n2-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(x>=0 && nums2[mid]*x <= v || x<0 && nums2[mid]*x > v) left = mid+1;
            else right = mid-1;
        }

        if(x>=0) return left;
        else return n2-left;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;

        while(left <= right){
            long long mid = left + (right-left)/2;
            long long count=0;
            for(int i = 0; i < n1; i++){
                count += f(nums2, nums1[i], mid);
            }

            if(count < k) left = mid+1;
            else right = mid-1;
        }

        return left;
    }
};