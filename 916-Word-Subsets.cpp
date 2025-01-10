class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        vector<int> frequency1;
        vector<int> frequency2(26, 0);

        for(int i = 0; i < 26; i++)
        {
            int max = 0;
            for(auto s : words2)
            {
                int count = 0;
                for(auto c : s)
                    if(i == (int) c - 'a')
                        count++;

                if(count >= max)
                    max = count;
            }
            frequency2[i] = max;
        }

        for(auto s : words1)
        {
            frequency1.assign(26, 0);
            for(auto c : s)
                frequency1[c - 'a']++;

            bool flag = true;
            for(int i = 0; i < 26; i++)
                if(frequency1[i] < frequency2[i])
                {
                    flag = false;
                    break;
                }
            
            if(flag)
                ans.push_back(s);
        }

        return ans;
    }
};