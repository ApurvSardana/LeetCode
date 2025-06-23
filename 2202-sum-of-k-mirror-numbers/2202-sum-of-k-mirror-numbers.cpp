class Solution {
public:
    vector<unsigned long long> numbers;
    int N;

    // Convert a base-k string (digits '0'..'0'+k-1) into its decimal value
    unsigned long long toDecimal(const string &s, int k) {
        unsigned long long newVal = 0; int n = s.length();
        int pos = n-1;
        while(pos >= 0) {
            unsigned long long rem = s[pos]-'0';                // rem is the “digit” at position pos
            newVal += rem * pow(k, pos);       // add rem * k^pos
            pos--;
        }
        return newVal;
    }

    bool isPalin(const string &s) {
        return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
    }

    // Check if decimal val is palindrome in base-10
    bool PalininBase10(unsigned long long val) {
        return isPalin(to_string(val));
    }

    void generatePalins(const string &s, int curr_length, int length, int k) {
        if ((int)numbers.size() == N) return;

        if (length % 2 == 0 && curr_length == length/2) {
            string finalS = s + string(s.rbegin(), s.rend());
            unsigned long long dec = toDecimal(finalS, k);
            if (dec != ULLONG_MAX && PalininBase10(dec))
                numbers.push_back(dec);
            return;
        }

        if (length % 2 == 1 && curr_length == length/2) {
            string rev_s(s.rbegin(), s.rend());
            for (char ch = '0'; ch < char('0'+k); ch++) {
                if ((int)numbers.size() == N) return;
                string cand = s + ch + rev_s;
                unsigned long long dec = toDecimal(cand, k);
                if (dec != ULLONG_MAX && PalininBase10(dec))
                    numbers.push_back(dec);
            }
            return;
        }

        if (curr_length != 0) 
            generatePalins(s + '0', curr_length+1, length, k);

        for (char ch = '1'; ch < char('0'+k); ch++) {
            if ((int)numbers.size() == N) break;
            generatePalins(s + ch, curr_length+1, length, k);
        }
    }

    long long kMirror(int k, int n) {
        N = n;
        numbers.clear();

        // single-digit k-mirror numbers
        for (int d = 1; d < k && (int)numbers.size() < N; d++)
            numbers.push_back(d);

        // generate longer palindromes
        for (int len = 2; (int)numbers.size() < N; len++)
            generatePalins("", 0, len, k);

        // sum up
        return accumulate(numbers.begin(), numbers.end(), 0ULL);
    }
};
