class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int originalNumber = x;
        long long newNumber = 0;
        while(x != 0)
        {
            int digit = x%10;
            newNumber = (10*newNumber) + digit;
            x/=10;
        }

        if(newNumber == originalNumber) return true;

        return false;
        
    }
};