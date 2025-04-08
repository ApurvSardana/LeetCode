class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> indices;

        for(int num : nums)
            freq[num]++;
        
        for(int i = 0; i < n; i++){
            if(freq[nums[i]] > 1)
                indices[nums[i]].push_back(i);
        }

        int last_index = -1;
        for(auto m : indices){
            vector<int> temp = m.second;
            last_index = max(last_index, temp[temp.size()-2]);
        }

        return ceil((double)(last_index+1)/3);
    }
};