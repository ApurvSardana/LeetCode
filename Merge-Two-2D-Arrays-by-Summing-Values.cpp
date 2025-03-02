class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        int i = 0; int j = 0;
        vector<vector<int>> ans;
        while(i < n1 && j < n2){
            vector<int> entry = {};
            auto p1 = nums1[i];
            auto p2 = nums2[j];

            if(p1[0] == p2[0]){
                entry.push_back(p1[0]);
                entry.push_back(p1[1]+p2[1]);
                i++;
                j++;
            }

            else if(p1[0] < p2[0]){
                entry = p1;
                i++;
            }

            else{
                entry = p2;
                j++;
            }
            ans.push_back(entry);
        }

        while(i < n1){
            ans.push_back(nums1[i++]);
        }

        while(j < n2){
            ans.push_back(nums2[j++]);
        }

        return ans;
    }
};