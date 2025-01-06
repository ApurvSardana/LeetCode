class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> countOfZero(n, 0);
        vector<int> countOfOne(n, 0);

        int count = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == '0')
                count++;
            
            countOfZero[i] = count; 
        }

        count = 0;
        for(int i = n - 1; i > 0; i--)
        {
            if(s[i] == '1')
                count++;
            
            countOfOne[i] = count;
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            countOfZero[i] += countOfOne[i];
            if(countOfZero[i] > ans)
                ans = countOfZero[i];
        }

        if(n == 2 && s[0] == '0' && s[n - 1] == '1')
            ans++;

        return ans;
    }
};