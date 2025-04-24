class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(nums[i]);

        int size = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            set<int> s2;
            s2.clear();
            for(int j = i; j < n; j++){
                s2.insert(nums[j]);
                if(s2.size() == size)
                    ans++;
            }
        }

        return ans;
    }
};