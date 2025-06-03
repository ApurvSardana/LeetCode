class Solution {
public:
    struct comp{
        bool operator()(vector<int> &a, vector<int> &b){
            if(a[0] < b[0]) return true;
            else if(a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comp());

        for(int i = 0; i < n; i++){
            int j = i+1; int max_end = intervals[i][1];
            while(j < n && intervals[j][0] <= max_end){
                max_end = max(max_end, intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], max_end});
            i = j-1;
        }
        // for(int i = 0; i < n; i++) cout << intervals[i][0] << ", " << intervals[i][1] << endl;
        return ans;
    }
};