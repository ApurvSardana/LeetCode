class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<vector<char>> arr(min(n, numRows));

        if(numRows == 1)
        return s;
       
        int i = 0;
        int j= 0;
        int flag = 1;
        while(s[i] != '\\0')
        {
            arr[j].push_back(s[i]);
            i++;

            if(j == 0)
                flag = 1;

            else if(j == numRows - 1)
                flag = 0;

            if(flag == 1)
                j++;

            else
                j--;
        }
       string ans = \\;

       for(auto p : arr)
            for(auto c : p)
                ans += c;

        return ans;
    }
};