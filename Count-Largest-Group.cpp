class Solution {
public:
    int sumOfDigits(int n){
        int sum = 0;
        while(n != 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int ans = 0; map<int, int> m; int max_size = 0;
        for(int i = 1; i <= n; i++){
            m[sumOfDigits(i)]++;
            max_size = max(max_size, m[sumOfDigits(i)]);
        }

        for(auto p : m)
            if(p.second == max_size)
                ans++;
        return ans;
    }
};