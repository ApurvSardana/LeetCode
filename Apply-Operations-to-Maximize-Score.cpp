class Solution {
public:
    const int MOD = 1e9 + 7;
    // We'll precompute SPF (Smallest Prime Factor) for numbers up to MAX.
    vector<int> spf;
    
    // Precompute SPF for all numbers from 1 to maxN.
    void computeSPF(int maxN) {
        spf.resize(maxN + 1);
        for (int i = 1; i <= maxN; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= maxN; i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= maxN; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }
    
    // Calculate prime score using SPF: count distinct prime factors.
    vector<int> calculatePS(vector<int> &nums) {
        int n = nums.size();
        vector<int> prime_score(n, 0);
        // Compute SPF up to the maximum element in nums.
        int maxVal = *max_element(nums.begin(), nums.end());
        computeSPF(maxVal);
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int prev = -1;
            int count = 0;
            while (num > 1) {
                int factor = spf[num];
                if (factor != prev) {
                    count++;
                    prev = factor;
                }
                num /= factor;
            }
            prime_score[i] = count;
        }
        return prime_score;
    }
    
    // Compute L using a monotonic stack.
    // L[i] = number of contiguous elements to the left of i with prime score less than prime_score[i].
    vector<int> calculateL(const vector<int>& prime_score) {
        int n = prime_score.size();
        vector<int> L(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && prime_score[st.top()] < prime_score[i])
                st.pop();
            int prev = st.empty() ? -1 : st.top();
            L[i] = i - prev - 1;
            st.push(i);
        }
        return L;
    }
    
    // Compute R using a monotonic stack.
    // R[i] = number of contiguous elements to the right of i with prime score less than or equal to prime_score[i].
    vector<int> calculateR(const vector<int>& prime_score) {
        int n = prime_score.size();
        vector<int> R(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && prime_score[st.top()] <= prime_score[i])
                st.pop();
            int next = st.empty() ? n : st.top();
            R[i] = next - i - 1;
            st.push(i);
        }
        return R;
    }
    
    // Iterative modular exponentiation.
    long long modPow(long long a, long long b) {
        long long result = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        // Step 1: Calculate the prime score for each element.
        vector<int> prime_score = calculatePS(nums);
        
        // Step 2: Compute L and R arrays using monotonic stacks.
        vector<int> L = calculateL(prime_score);
        vector<int> R = calculateR(prime_score);
        
        // Step 3: Use a priority queue to greedily pick the highest numbers.
        // We also compute the number of subarrays in which an element can be used.
        // That number is (L[i] + 1) * (R[i] + 1).
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});
        
        long long ans = 1;
        while (k > 0) {
            int num = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            long long cnt = (long long)(L[index] + 1) * (R[index] + 1);
            int times = min((long long)k, cnt);
            k -= times;
            ans = (ans * modPow(num, times)) % MOD;
        }
        return ans;
    }
};
