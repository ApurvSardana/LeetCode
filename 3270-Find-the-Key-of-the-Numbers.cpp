class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        vector<int> digits(4);
        int key = 0;

        for(int i = 0; i < 4; i++)
        {
            digits[i] = min(min(num1%10, num2%10), num3%10);

            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }

        for(int i = digits.size() - 1; i >= 0; i--)
        key = 10*key + digits[i];

        return key;
    }
};