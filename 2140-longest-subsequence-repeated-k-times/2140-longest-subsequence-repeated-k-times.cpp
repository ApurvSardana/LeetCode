class Solution {
public:
    bool isValid(string &s, string &p, int k){
        int n = s.length(), m = p.length();
        int i = 0, j = 0;
        int count = 0;
        while(i < n){
            if(count >= k) return true;

            if(j == m){
                count++;
                j = 0;
            }

            if(s[i] == p[j]){
                i++;j++;
            }

            else{
                i++;
            }
        }

        if(j == m) count++;
        return count >= k;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        vector<int> f(26, 0);
        for(char &ch : s) f[ch-'a']++;

        vector<char> candidates;
        for(int i = 25; i >= 0; i--){
            if(f[i] >= k) candidates.push_back('a'+i);
        }

        queue<string> q;
        for(char &ch : candidates) q.push(string(1, ch));

        string ans = "";
        while(!q.empty()){
            string pot = q.front();
            q.pop();

            if(pot.length() > ans.length() || (pot.length() == ans.length() && (pot > ans))){
                ans = pot;
            }

            for(char ch : candidates){
                string temp = pot + ch;
                if(isValid(s, temp, k)) q.push(temp);
            }
        }

        return ans;
    }
};