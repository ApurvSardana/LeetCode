class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;

        int i = 0; int j = 0;
        int z = m;
        while(i < z && j < n){
            if(nums1[i] > nums2[j]){
                for(int k = z; k > i; k--) nums1[k] = nums1[k-1];
                z++;
                nums1[i] = nums2[j];
                j++;
            }
            i++;
        }

        while(z < (m+n) && j < n){
            nums1[z++] = nums2[j++];
        }
    }
};