class comp
{
    public:
    bool operator()(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);

        if((s1 + s2) > (s2 + s1))
        return true;

        else
        return false;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp());

        string ans = "";

        for(auto n : nums)
        {
            ans += to_string(n);
        }

        while(ans[0] == '0')
        ans.erase(ans.begin());

        if(ans == "")
        ans = "0";

        return ans;
    }
};