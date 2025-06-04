class Solution {
public:
    int ans;
    void merge(vector<long long> &nums, int l, int q, int r){
        int len1 = q-l, len2 = r-q+1;
        vector<long long> temp(len1+len2);

        for(int i = q; i <= r; i++){
            int index = upper_bound(nums.begin()+l, nums.begin()+q, 2*nums[i]) - nums.begin();
            if(index >= q) continue;
            ans += q-index;
        }

        int i = l; int j = q; int k = 0;
        while(i < q && j <= r){
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            
            else{
                temp[k++] = nums[j++];
            }
        }

        while(j <= r){
            temp[k++] = nums[j++];
        }

        while(i < q){
            temp[k++] = nums[i++];
        }

        k = 0;
        i = l;
        while(k < len1+len2){
            nums[i++] = temp[k++];
        }
    }
    void mergeSort(vector<long long> &nums, int l, int r){
        if(l < r){
            int mid = l + (r-l)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);

            merge(nums, l, mid+1, r);
        }
    }
    int reversePairs(vector<int>& nums) {
        ans = 0;
        vector<long long> nums2;
        for(int i = 0; i < nums.size(); i++){
            nums2.push_back((long long)nums[i]);
        }
        mergeSort(nums2, 0, nums.size()-1);
        return ans;
    }
};