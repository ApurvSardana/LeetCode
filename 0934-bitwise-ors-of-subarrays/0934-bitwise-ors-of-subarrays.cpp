class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> ans;
        unordered_set<int> prev;

        for(int i = 0; i < n; i++){
            int val = arr[i];
            unordered_set<int> curr;

            curr.insert(val);
            ans.insert(val);

            for(int num : prev){
                curr.insert(num | val);
                ans.insert(num | val);
            }

            prev = curr;
        }

        return ans.size();
    }
};