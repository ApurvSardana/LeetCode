class Solution {
public:
int MOD = 1000000007;
    long long pow1(long long a, long long b)
    {
        long long ans;
        if(b == 0) return 1;
        
            ans = pow1(a, b/2);
            ans = ((ans % MOD)* (ans % MOD)) % MOD;
            if(b % 2 != 0)
            ans = ((ans % MOD) * (a % MOD)) % MOD;

return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenIndices, oddIndices;
        evenIndices  = oddIndices = 0;
      if(n % 2 == 0)
      {
        evenIndices = oddIndices = n / 2;
      }
      else
      {
        evenIndices = (n + 1) / 2;
        oddIndices = (n -  1) / 2;
      }
      
      return (((pow1(5, evenIndices) % MOD) * (pow1(4, oddIndices) % MOD))% MOD);
    }
};