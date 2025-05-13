class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        static const int MOD = 1e9 + 7;
        long long len = s.size();

        // f[i] = how many of character 'a'+i we have right now
        vector<long long> f(26, 0);
        for (char c : s)
            f[c - 'a']++;

        // Do exactly t transformations
        while (t--) {
            vector<long long> nf(26, 0);

            // Shift non-'z' forward
            for (int i = 0; i < 25; i++) {
                nf[i + 1] = (nf[i + 1] + f[i]) % MOD;
            }

            // Handle all the 'z's
            long long zcount = f[25];
            // Each 'z' → "ab", so we get one 'a' and one 'b' for each.
            nf[0] = (nf[0] + zcount) % MOD;   // 'a'
            nf[1] = (nf[1] + zcount) % MOD;   // 'b'
            // And length grows by zcount
            len = (len + zcount) % MOD;

            // Move on
            f.swap(nf);
        }

        return (int)len;
    }
};
