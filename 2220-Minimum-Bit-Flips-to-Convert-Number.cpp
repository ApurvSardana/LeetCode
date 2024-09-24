class Solution {
public:
    string bin_str(int a)
    {
        if(a == 0) return "0";
        
        string ans = "";
        while(a > 0)
        {
        ans = ans + (char)(a%2);
        a /= 2;
        }

        // if((temp%2) != 0)
        // ans += '0';

        return ans;
    }

    int minBitFlips(int start, int goal) {
        string s1 = bin_str(start);
        string s2 = bin_str(goal);

            
        int count = 0;

        int len = min(s1.length(), s2.length());
        int i = 0;

        if(s2 == "0")
        {
            for(auto i : s1)
            if(i == (char)(1))
            count++;
            return count;
        }

        if(s1 == "0")
        {
            for(auto i : s2)
            if(i == (char)(1))
            count++;
            return count;
        }
        for( ;i < len; i++)
        {
            if((char)s1[i] != (char)s2[i])
            count++;
        }


        if(s1.length() > s2.length())
        {
            while(i < s1.length())
            {
                
                if(s1[i] == (char)(1))
                {
                    count++;
                }

                    i++;
            }
        }
            
        else if(s2.length() > s1.length())
        {
            while(i < s2.length())
            {

                if(s2[i] == (char)(1))
                    count++;

                    i++;
            }
        }

        return count;
    }
};