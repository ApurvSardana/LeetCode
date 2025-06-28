class Solution {
public:
    int count, K, N; string ans;
    void f(string curr, char ch, vector<bool> &vis, bool &found){
        // //if(curr.length() == N){
        //     cout << curr << " : " << count << endl;
        // //}

        if(found) return;
        
        if(curr.length() == N){
            count++;
            if(count == K){
                ans = curr;
                found = true;
                return;
            }
        }

        for(int i = 1; i <= N; i++){
            if(vis[i]) continue;

            curr += '0'+i;
            vis[i] = true;
            f(curr, '0'+i+1, vis, found);
            curr.pop_back();
            vis[i] = false;
        }
    }

    string getPermutation(int n, int k) {
        count = 0; K = k; N = n;
        string curr = ""; vector<bool> vis(n, false);
        bool found = false;
        for(int i = 1; i <= n; i++){
            f(curr, '0'+i, vis, found);
        }

        return ans;
    }
};