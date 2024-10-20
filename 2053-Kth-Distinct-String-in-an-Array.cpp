class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int size = arr.size();
        unordered_map<string, int> m;

        for(auto s : arr)
        m[s]++;

        int i = 0;
        int count = 0;
        while(i < size)
        {
            if(m[arr[i]] == 1)
            count++;

            if(count == k)
            return arr[i];

            i++;
        }

        return "";
        
    }
};