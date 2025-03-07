class Solution {
public:
    int N = 1000001;
    vector<bool> primes;

    void sieve(){
        primes.assign(1000001, true);
        primes[0] = primes[1] = false;

        for(int i = 2; (long long)i*i < N; i++)
            if(primes[i])
                for(long long j = (long long)i*i; j < N; j += i)
                    primes[j] = false;
    }

    vector<int> closestPrimes(int left, int right) {
        int n1 = -1;
        int ans1 = -1; int ans2 = -1;
        int diff = INT_MAX;

        sieve();
                
        for(int i = left; i <= right; i++){
            if(primes[i] && n1 == -1)
                n1 = i;
            
            else if(primes[i]){
                if(i - n1 < diff){
                    diff = i - n1;
                    ans1 = n1;
                    ans2 = i;
                }
                n1 = i;
            }
        }
        return {ans1, ans2};
    }
};