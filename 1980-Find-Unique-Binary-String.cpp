class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<bool> one_count(n+1, false);

        for(int i = 0; i < n; i++){
            string s = nums[i];
            int count = 0;

            for(int j = 0; j < n; j++)
                if(s[j] == '1')
                    count++;

            one_count[count] = true;
        }

        string ans = "";
        for(int i = 0; i <= n; i++)
            if(!one_count[i]){
                for(int j = 0; j < i; j++)
                    ans += '1';
                break;
            }

        while(ans.length() != n)
            ans += '0';

        return ans;
    }
};