class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(); vector<int> freq(7, 0), freq_in_tops(7, 0), freq_in_bottoms(7, 0);

         for(int i = 0; i < n; i++){
            freq[tops[i]]++;

            if(tops[i] != bottoms[i])
                freq[bottoms[i]]++;

            freq_in_tops[tops[i]]++; freq_in_bottoms[bottoms[i]]++;
         }

        int ans = INT_MAX;
        for(int i = 1; i <= 6; i++)
            if(freq[i] == n)
                ans = min(ans, n-max(freq_in_tops[i], freq_in_bottoms[i]));
            
        return ans == INT_MAX ? -1 : ans;
    }
};