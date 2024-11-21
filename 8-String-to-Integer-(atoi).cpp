class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int flag = 0;

        int i = 0;

        while(s[i] == ' ')
            i++;
        
        if(s[i] == '-')
        {
            flag = 1;
            i++;
        }

        else if(s[i] == '+')
            i++;

        while(s[i] != '\\0')
        {
            if(s[i] >= 48 && s[i] <= 57)
            {
                ans = 10*ans + (s[i] - 48);

                if(ans > INT_MAX && flag == 0)
                    return INT_MAX;

                else if(ans > INT_MAX && flag == 1)
                    return INT_MIN;
            }

            else
            break;

            i++;
        }
        return (flag == 0) ? (int)ans : (int)-ans;
    }
};