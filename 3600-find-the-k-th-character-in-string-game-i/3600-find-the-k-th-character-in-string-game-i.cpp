class Solution {
public:
    void operate(string &s){
        int n = s.length();
        for(int i = 0; i < n; i++){
            int c = s[i]-'a';
            c = (c+1)%26;
            s += ('a' + c);
        }
    }
    char kthCharacter(int k) {
        string s(1, 'a');
        int n = ceil((double)log2(k));

        while(n--){
            operate(s);
        }

        return s[k-1];
    }
};