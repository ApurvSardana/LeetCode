class Solution {
public:
    double myPow(double x, int n) {
        if(n >= 0)
        {
            double ans = 1.0;

        if(n == 0) 
        return 1.0;

        else 
        {
            ans = myPow(x, n/2);
            ans = ans * ans;
            if (n%2 == 1)
            ans = ans * x;

            
        }
        return ans;
        }


        else
        {
            n = abs(n);

            double ans = 1.0;

            if(n == 0) 
            return 1.0;

          else 
          {
            ans = myPow(x, n/2);
            ans = ans * ans;
            if (n%2 == 1)
            ans = ans * x;

            
        }
        return 1.0/ans;
        }
        
    }
};