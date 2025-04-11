class Solution {
public:
    bool f(int n, int num_digits){
        int total_sum = 0, half_sum = 0;
        for(int i = 0; i < num_digits/2; i++){
            int digit = n%10;
            half_sum += digit;
            n /= 10;
        }

        total_sum = half_sum;
        while(n != 0){
            int digit = n%10;
            total_sum += digit;
            n /= 10;
        }

        return 2*half_sum == total_sum;
    }
    int countDigits(int n){
        int ans = 0;
        while(n != 0){
            n /= 10;
            ans++;
        }
        return ans;
    }

    bool symmetric(int n){
        int num_digits = countDigits(n);

        if(num_digits & 1) return false;

        return f(n, num_digits);
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++){
            if(symmetric(i))
                count++;
        }
        return count;
    }
};