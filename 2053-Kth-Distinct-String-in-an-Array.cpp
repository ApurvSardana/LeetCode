class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int size = arr.size();
        unordered_map<string, int> m;
        vector<int> mark(size, 0);

        for(auto s : arr)
        m[s]++;

        for(int i = 0; i < size; i++)
        if(m[arr[i]] == 1) mark[i] = 1;

        for(auto p : mark)
        cout << p << " ";

        int i = 0;
        int count = 0;
        while(count < k && i < size)
        {
            if(mark[i] == 1)
            count++;

            if(count == k)
            return arr[i];

            i++;
        }

        return "";
        
    }
};