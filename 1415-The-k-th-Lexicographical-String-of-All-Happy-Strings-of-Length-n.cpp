class Solution {
public:
    vector<string> v;
    bool happy(const string &s){
        int n = s.length();

        for(int i = 0; i < n-1; i++)
            if(s[i] == s[i+1])
                return false;

        return true;
    }

    void generate(string s, int index, const int &n){
        if(index > n)
            return;

        if(s.length() == n && happy(s) == true)
            v.push_back(s);
        
        else{
            generate(s+'a', index+1, n);
            generate(s+'b', index+1, n);
            generate(s+'c', index+1, n);
        }
    }

    string getHappyString(int n, int k) {
        string s = "";
        generate(s, 0, n);

        cout << v.size() << endl;

        if(v.size() < k)
            return "";

        return v[k-1];
    }
};