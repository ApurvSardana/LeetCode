class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> hash_set;
        int length = 0;

        for(auto n : arr1)
        {
            string str = to_string(n);
            string pre_str = "";
            for(int i = 0; i < str.length(); i++)
            {
                pre_str += str[i];
                hash_set.insert(pre_str);
            }
        }

        for(auto m : arr2)
        {
            string str = to_string(m);
            string pre_str = "";
            for(int i = 0; i < str.length(); i++)
            {
                pre_str += str[i];
                if(hash_set.find(pre_str) != hash_set.end())
                length = max(length, i + 1);
            }
        }

        return length;
    }
};