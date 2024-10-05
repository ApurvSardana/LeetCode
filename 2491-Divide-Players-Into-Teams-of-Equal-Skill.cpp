class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;

        sort(skill.begin(), skill.end());

        vector<pair<int, int>> vec(skill.size() / 2);

        int i = 0;
        int j = skill.size() - 1;
        int sum = skill[i] + skill[j];

        while(i < j)
        {
            if(skill[i] + skill[j] == sum)
            {
                vec.push_back({skill[i], skill[j]});
                i++;
                j--;
            }

            else
            {
                return -1;
            }
        }

        for(auto n : vec)
        {
            ans += n.first * n.second;
        }

    return ans;
    }
};