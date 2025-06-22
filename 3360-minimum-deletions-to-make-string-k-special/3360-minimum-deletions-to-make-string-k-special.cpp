class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int> freq(26, 0);
        vector<int> f;
        for(int i = 0; i < n; i++)
            freq[word[i]-'a']++;
        
        for(int i : freq){
            if(i != 0) f.push_back(i);
        }

        sort(f.begin(), f.end());

        vector<int> ps(f.size()+1, 0), ss(f.size()+1, 0);
        ps[0] = 0; ss[0] = 0;
        for(int i = 1; i <= f.size(); i++){
            ps[i] = ps[i-1] + f[i-1];
        }

        for(int i = 1; i <= f.size(); i++){
            ss[i] = ss[i-1]+f[f.size()-i];
        }

        // for(int i = 0; i < f.size(); i++) cout << f[i] << " ";
        // cout << endl;

        // for(int i : ps) cout << i << " ";
        // cout << endl;
        // for(int i : ss) cout << i << " ";
        // cout << endl;
        int ans = n;
        for(int i = 0; i < f.size(); i++){
            int index = (upper_bound(f.begin()+i+1, f.end(), k+f[i])-f.begin())-1;
            int del = 0;
            for(int j = index+1; j < f.size(); j++)
                del += (f[j]-k-f[i]);
            
            del += ps[i];
            //cout << index << " : " << del << endl;
            ans = min(ans, del);
        }

        return ans;
    }
};