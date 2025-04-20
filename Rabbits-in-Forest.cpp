class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> freq;

        for(int i : answers)
            freq[i]++;
        
        int ans = 0;
        for(auto p : freq){
            int num = p.first;
            int f = p.second;

            ans += ((f+num)/(num+1))*(num+1);
        }

        return ans;
    }
};