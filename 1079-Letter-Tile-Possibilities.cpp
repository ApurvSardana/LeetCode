class Solution {
public:
    set<string> s;
    int n;
    
    int fact(int x){
        if(x == 0 || x == 1)
            return 1;
        
        else
            return x*fact(x-1);
    }
    void f(const string &tiles, int index, string str){
        if(str != "")
            s.insert(str);

        if(index < n-1){
            f(tiles, index+1, str + tiles[index]);
            f(tiles, index+1, str);
        }

        else if(index == n-1){
            s.insert(str + tiles[n-1]);
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        
        n = tiles.length();
        f(tiles, 0, "");

        vector<int> freq(26, 0);
        int ans = 0;
        for(auto word : s){
            int len = word.length();
            freq.assign(26, 0);
            for(auto ch : word){
                freq[ch - 'A']++;
            }

            int lenf = fact(len);

            for(int i = 0; i < 26; i++)
                lenf /= fact(freq[i]);
            
            ans += lenf;
        }
        return ans;
    }
};