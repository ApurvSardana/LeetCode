class Solution {
public:
    int countWhites(string &s, int l, int r){
        int count = 0;
        for(int i = l; i <= r; i++)
            if(s[i] == 'W')
                count++;
        return count;
    }
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        for(int i = 0; i < n; i++){
            int count = 0;
            while(blocks[i] == 'B'){
                count++;
                i++;
            }
            if(count >= k)
                return 0;
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < n - k + 1; i++){
            int whites = countWhites(blocks, i, i+k-1);
            ans = min(ans, whites);
        }
        return ans;
    }
};