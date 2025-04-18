class Solution {
public:
    string helper(string s, int moves, int n){
        if(moves == n)
            return s;
        
        string new_string = \\; map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            if(i != 0 && s[i] != s[i-1]){
                new_string += to_string(m[s[i-1]]) + s[i-1];
                m[s[i]] = 1;
            }

            else
                m[s[i]]++;
        }

        new_string += to_string(m[s[s.length()-1]]) + s[s.length()-1];
        cout << new_string << endl;
        return helper(new_string, moves+1, n);
    }
    string countAndSay(int n) {
        return helper(\1\, 1, n);
    }
};