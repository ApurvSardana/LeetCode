class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end(), [&](string &a, string &b){return a.length() < b.length();});
        set<string> st;

        for(string s : folder){
            string str = ""; bool valid = true;
            for(int i = 0; i < s.length(); i++){
                str += s[i];
                if(i == s.length()-1 || (s[i+1] == '/')){
                    if(st.find(str) != st.end()){
                        valid = false;
                        break;
                    }
                }
            }

            if(valid) st.insert(str);
        }

        return vector<string> (st.begin(), st.end());
    }
};