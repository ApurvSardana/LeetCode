class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        multiset<char> st1, st2;
        
        for(int i = 0; i < n; i++){
            st1.insert(s1[i]);
            st2.insert(s2[i]);
        }

        if(st1 != st2) return false;

        int count = 0;
        for(int i = 0; i < n; i++)
            if(s1[i] != s2[i])
                count++;

        return (count == 2 || count == 0);
    }
};