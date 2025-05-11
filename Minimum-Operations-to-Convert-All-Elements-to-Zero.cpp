class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(); int ans = 0;
        vector<pair<int, int>> a;
        set<int> s{n};
        for(int i = 0; i<n ; i++){
            //if(nums[i] == 0) s.insert(i);
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        for(int i = 0; i<n; i++){
            if(a[i].first != 0) ans++;
            s.insert(a[i].second);
            while(i < n-1 && a[i].first == a[i+1].first){
                int nextSame = a[i+1].second;
                int nextSmall = *s.upper_bound(a[i].second);

                if(nextSame > nextSmall) break;
                //s.insert(a[i].second);
                i++;
                s.insert(a[i].second);
            }
            //s.insert(a[i].second);
        }
        return ans;
    }
};