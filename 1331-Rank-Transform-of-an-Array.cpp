class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        if(arr.size() == 0) return arr;
        vector<int> original_arr(arr.size());
        
        for(int i = 0; i < arr.size(); i++)
        {
            original_arr[i] = arr[i];
        }

        sort(arr.begin(), arr.end());

        unordered_map <int, int> m;
        m[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] == arr[i - 1])
            m[arr[i]] = m[arr[i - 1]];

            else
            m[arr[i]] = m[arr[i - 1]] + 1;
        }

        for(int i = 0; i < arr.size(); i++)
        {
            original_arr[i] = m[original_arr[i]];
        }
        return original_arr;
    }
};