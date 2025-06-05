class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        vector<int> m(26, 0);
        for(int i = 0; i < 26; i++) m[i] = i;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                m[s1[j]-'a'] = min(m[s1[j]-'a'], m[s2[j]-'a']);
                m[s2[j]-'a'] = min(m[s2[j]-'a'], m[s1[j]-'a']);
            }
        }

        string ans = "";

        // for(int i = 0; i < 26; i++){
        //     cout << (char)('a'+i) << " : " << (char)(m[i]+'a') << endl;
        // }

        for(int i = 0; i < baseStr.length(); i++)
            ans += (char)(m[baseStr[i]-'a']+'a');
        
        return ans;
    }
};